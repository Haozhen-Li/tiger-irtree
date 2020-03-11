#include "util.h"
#include "errormsg.h"
#include "symbol.h"
#include "types.h"
#include "temp.h"
#include "tree.h"
#include "frame.h"
#include "absyn.h"
#include "translate.h"
#include "semant.h"
#include "env.h"

struct expty transExpList(S_table venv, S_table tenv, A_expList a, Tr_level level);
T_stm transFields(S_table venv, S_table tenv, T_stm stm, int i, void *r, Ty_fieldList rfields, A_efieldList fields, Tr_level level);
Ty_fieldList transTyFields(S_table tenv, A_fieldList fields);

Ty_ty actual_ty(Ty_ty t){
    if(t->kind == Ty_name){
        return actual_ty(t->u.name.ty);
    }
    else return t;
}

bool ty_comp(Ty_ty t1, Ty_ty t2){
    if(t1 == t2) return TRUE;
    if(t1 == Ty_Nil() && t2->kind == Ty_record) return TRUE;
    if(t2 == Ty_Nil() && t1->kind == Ty_record) return TRUE;
    return FALSE;
}

struct expty expTy(T_exp exp, Ty_ty ty) {
    struct expty e;
    e.exp=exp;
    e.ty=ty;
    return e;
}

T_expList transArgs(A_pos pos, S_table venv, S_table tenv, Ty_tyList formals, A_expList args, Tr_level level){
    if(!formals && !args) return NULL;
    else if(!formals || !args){
        EM_error(pos, "wrong number of arguments");
        return NULL;
    }
    struct expty arg = transExp(venv, tenv, args->head, level);
    if(!ty_comp(arg.ty, actual_ty(formals->head))){
        EM_error(args->head->pos, "argument type mismatch");
        return NULL;
    }
    return T_ExpList(arg.exp, transArgs(pos, venv, tenv, formals->tail, args->tail, level));
}

struct expty transVar(S_table venv, S_table tenv, A_var v, Tr_level level) {
    switch(v->kind) {
        case A_simpleVar: {
            E_enventry x = S_look(venv,v->u.simple);
            if (x && x->kind==E_varEntry)
                return expTy(/*NULL*/Tr_simpleVar(x->u.var.access), actual_ty(x->u.var.ty));
            else {EM_error(v->pos,"undefined variable %s", S_name(v->u.simple));
            return expTy(NULL,Ty_Int());}
        }
        case A_fieldVar: {
            struct expty base = transVar(venv, tenv, v->u.field.var, level);
            Ty_ty r = base.ty;
            if(r && r->kind == Ty_record){
                Ty_fieldList rfields = r->u.record;
                int i;
                for(i = 0; ; i++){
                    if(!rfields){EM_error(v->pos,"no field named %s in record", S_name(v->u.field.sym));
                        return expTy(NULL, Ty_Int());}
                    if(rfields->head->name == v->u.field.sym){
                        break;
                    }
                    rfields = rfields->tail;
                }
                return expTy(Tr_fieldVar(base.exp, i), actual_ty(rfields->head->ty));
            }
            else {EM_error(v->pos,"field access on non-record expression");
            return expTy(NULL,Ty_Int());}
        }
        case A_subscriptVar: {
            struct expty base = transVar(venv, tenv, v->u.subscript.var, level);
            struct expty index = transExp(venv, tenv, v->u.subscript.exp, level);
            if(base.ty->kind != Ty_array){EM_error(v->pos,"indexing a non-array expression");
                        return expTy(NULL, Ty_Int());}
            if(index.ty != Ty_Int()){EM_error(v->pos,"array index not an int");
                        return expTy(NULL, Ty_Int());}                        
            return expTy(Tr_subscriptVar(base.exp, index.exp), actual_ty(base.ty->u.array));
        }
    }
}

struct expty transExp(S_table venv, S_table tenv, A_exp a, Tr_level level) {
    switch(a->kind) {
        case A_varExp:
            return transVar(venv, tenv, a->u.var, level);
        case A_intExp:
            return expTy(Tr_int(a->u.intt), Ty_Int());
        case A_stringExp:
            return expTy(Tr_string(a->u.stringg), Ty_String());
        case A_nilExp:
            return expTy(Tr_nil(), Ty_Nil());
        case A_assignExp: {
            struct expty lhs = transVar(venv, tenv, a->u.assign.var, level);
            struct expty rhs = transExp(venv, tenv, a->u.assign.exp, level);
            if(!ty_comp(lhs.ty, rhs.ty)){
                EM_error(a->u.var->pos, "type mismatch in assignment");
                return expTy(NULL, Ty_Void());
            }
            return expTy(Tr_assign(lhs.exp, rhs.exp), Ty_Void());
        }
        case A_seqExp: {
            return transExpList(venv, tenv, a->u.seq, level);
        }
        case A_recordExp: {
            Ty_ty rec = actual_ty(S_look(tenv, a->u.record.typ));
            Ty_fieldList rfields = rec->u.record;
            void *r = Tr_start_record();
            T_stm fields = transFields(venv, tenv, NULL, 0, r, rfields, a->u.record.fields, level);
            return expTy(Tr_finish_record(r, a->u.record.fields, fields), actual_ty(rec));
        }
        case A_arrayExp: {
            Ty_ty arr = actual_ty(S_look(tenv, a->u.array.typ));
            if(arr->kind != Ty_array){
                EM_error(a->pos, "not an array type");
                return expTy(NULL, Ty_Void());
            }
            Ty_ty ty = actual_ty(arr->u.array);
            struct expty size = transExp(venv, tenv, a->u.array.size, level);
            if(size.ty != Ty_Int()){
                EM_error(a->u.array.size->pos, "array size must be int");
                return expTy(NULL, Ty_Void());
            }
            struct expty init = transExp(venv, tenv, a->u.array.init, level);
            if(!ty_comp(init.ty, ty)){
                EM_error(a->u.array.init->pos, "type mismatch in array initializer");
                return expTy(NULL, Ty_Void());
            }
            return expTy(Tr_array(size.exp, init.exp), arr);
        }
        case A_ifExp: {
            struct expty cond = transExp(venv, tenv, a->u.iff.test, level);
            if(cond.ty != Ty_Int()){
                EM_error(a->u.iff.test->pos, "condition of if-then-else must be int");
                return expTy(NULL, Ty_Void());
            }
            struct expty tcase = transExp(venv, tenv, a->u.iff.then, level);
            if(!a->u.iff.elsee){
                if(tcase.ty != Ty_Void()){
                    EM_error(a->u.iff.then->pos, "if without else must not produce a value");
                    return expTy(NULL, Ty_Void());
                }
                return expTy(Tr_if(cond.exp, tcase.exp, NULL), Ty_Void());
            }
            else{
                struct expty fcase = transExp(venv, tenv, a->u.iff.elsee, level);
                if(!ty_comp(tcase.ty, fcase.ty)){
                    EM_error(a->u.iff.then->pos, "types of branches must match");
                    return expTy(NULL, Ty_Void());
                }
                return expTy(Tr_if(cond.exp, tcase.exp, fcase.exp), tcase.ty);
            }
        }
        case A_whileExp: {
            struct expty test = transExp(venv, tenv, a->u.whilee.test, level);
            if(test.ty != Ty_Int()){
                EM_error(a->u.iff.test->pos, "loop condition must be int");
                return expTy(NULL, Ty_Void());
            }
            struct expty body = transExp(venv, tenv, a->u.whilee.body, level);
            if(body.ty != Ty_Void()){
                EM_error(a->u.iff.test->pos, "loop body must not produce a value");
                return expTy(NULL, Ty_Void());
            }
            return expTy(Tr_while(test.exp, body.exp), Ty_Void());
        }
        case A_forExp: {
            A_var i = A_SimpleVar(a->pos, a->u.forr.var);
            return transExp(venv, tenv, A_LetExp(a->pos, A_DecList(
                A_VarDec(a->pos, a->u.forr.var, S_Symbol("int"), a->u.forr.lo), A_DecList(
                A_VarDec(a->pos, S_Symbol("__limit"), S_Symbol("int"), a->u.forr.hi), NULL)),
                //ignoring limit overflow
                A_WhileExp(a->pos, A_OpExp(a->pos, A_leOp, A_VarExp(a->pos, i),
                                                           A_VarExp(a->pos, A_SimpleVar(a->pos, S_Symbol("__limit")))),
                                A_SeqExp(a->u.forr.body->pos, A_ExpList(a->u.forr.body,
                                A_ExpList(A_AssignExp(a->u.forr.body->pos, i,
                                    A_OpExp(a->u.forr.body->pos, A_plusOp, A_VarExp(a->pos, i), A_IntExp(a->u.forr.body->pos, 1))), NULL))))), level);
        }
        case A_callExp: {
            E_enventry sig = S_look(venv, a->u.call.func);
            if(!sig){
                EM_error(a->pos, "undefined function");
                return expTy(NULL, Ty_Void());
            }
            if(sig->kind != E_funEntry){
                EM_error(a->pos, "not a function");
                return expTy(NULL, Ty_Void());
            }
            T_expList args = transArgs(a->pos, venv, tenv, sig->u.fun.formals, a->u.call.args, level);
            Ty_ty ret = sig->u.fun.result;
            return expTy(Tr_call(sig->u.fun.label, args), actual_ty(ret));
        }
        case A_letExp: {
            struct expty exp;
            A_decList d;
            S_beginScope(venv);
            S_beginScope(tenv);
            T_stm inits = NULL;
            for (d = a->u.let.decs; d; d=d->tail){
                T_stm init = transDec(venv, tenv, d->head, level);
                if(init){
                    if(!inits) inits = init;
                    else inits = T_Seq(inits, init);
                }
            }
            exp = transExp(venv, tenv, a->u.let.body, level);
            S_endScope(tenv);
            S_endScope(venv);
            if(inits) return expTy(T_Eseq(inits, exp.exp), exp.ty);
            else return exp;
        }
        case A_opExp: {
            A_oper oper = a->u.op.oper;
            struct expty left = transExp(venv, tenv, a->u.op.left, level);
            struct expty right = transExp(venv, tenv, a->u.op.right, level);
            /**/T_exp e = Tr_binOp(a->u.op.oper, left.exp, right.exp);
            if (oper == A_plusOp || oper == A_minusOp || oper == A_timesOp || oper == A_divideOp
                || oper == A_ltOp || oper == A_leOp || oper == A_gtOp || oper == A_geOp) {
                if (left.ty->kind != Ty_int)
                    EM_error(a->u.op.left->pos, "integer required");
                if (right.ty->kind!=Ty_int)
                    EM_error(a->u.op.right->pos,"integer required");
                return expTy(/*NULL*/e,Ty_Int());
            }
            else{ // eq or neq
                if (!ty_comp(left.ty, right.ty))
                    EM_error(a->u.op.left->pos,"incomparable types");
                return expTy(/*NULL*/e,Ty_Int());
            }
        }
    }
    assert(0); /* should have returned from some clause of the switch */
}

T_stm transFields(S_table venv, S_table tenv, T_stm stm, int i, void *r, Ty_fieldList rfields, A_efieldList fields, Tr_level level){
    if(!rfields) return NULL;
    if(!fields) return NULL;
    struct expty e = transExp(venv, tenv, fields->head->exp, level);
    if(!ty_comp(e.ty, actual_ty(rfields->head->ty))){
        EM_error(fields->head->exp->pos, "field type mismatch");
        return NULL;
    }
    T_stm stm2 = Tr_add_field(stm, i, r, e.exp);
    if(!rfields->tail && !fields->tail) return stm2;
    else if(!rfields->tail || !fields->tail){
        EM_error(fields->head->exp->pos, "wrong number of fields");
        return NULL;
    }
    else return transFields(venv, tenv, stm2, i + 1, r, rfields->tail, fields->tail, level);
}

struct expty transExpList(S_table venv, S_table tenv, A_expList a, Tr_level level) {
    if(!a){
        return expTy(Tr_nil(), Ty_Void());
    }
    struct expty lhs = transExp(venv, tenv, a->head, level);
    if(!a->tail){
        return lhs;
    }
    struct expty rhs = transExpList(venv, tenv, a->tail, level);
    return expTy(T_Eseq(T_Exp(lhs.exp), rhs.exp), actual_ty(rhs.ty));
}

U_boolList escapes(Ty_tyList formalTys){
    U_boolList result = NULL;
    for(; formalTys; formalTys = formalTys->tail)
        result = U_BoolList(TRUE, result);
    return result;
}

Ty_fieldList transTyFields(S_table tenv, A_fieldList fields){
    if(!fields) return NULL;
    Ty_ty t = S_look(tenv, fields->head->typ);
    if(!t){
        EM_error(fields->head->pos, "undeclared type %s\n", S_name(fields->head->name));
        return NULL;
    }
    return Ty_FieldList(Ty_Field(fields->head->name, t), transTyFields(tenv, fields->tail));
}

Ty_ty transTy(S_table tenv, A_ty a){
    switch(a->kind){
        case A_nameTy: {
            Ty_ty t = S_look(tenv, a->u.name);
            if(!t){
                EM_error(a->pos, "undeclared type %s\n", S_name(a->u.name));
                return NULL;
            }
            return t;
        }
        case A_recordTy: {
            return Ty_Record(transTyFields(tenv, a->u.record));
        }
        case A_arrayTy: {
            Ty_ty t = S_look(tenv, a->u.array);
            if(!t){
                EM_error(a->pos, "undeclared type %s\n", S_name(a->u.name));
                return NULL;
            }
            return Ty_Array(t);
        }
    }
}

Ty_tyList makeFormalTyList(S_table tenv, A_fieldList params){
    if(!params) return NULL;
    Ty_ty t = S_look(tenv, params->head->typ);
    if(!t){
        EM_error(params->head->pos, "undefined type %s\n", S_name(params->head->typ));
        return NULL;
    }
    return Ty_TyList(t, makeFormalTyList(tenv, params->tail));
}

int len(Tr_accessList l){
    int r = 0;
    for(; l; l = l->tail) r++;
    return r;
}

int tlen(Ty_tyList l){
    int r = 0;
    for(; l; l = l->tail) r++;
    return r;
}

int elen(U_boolList l){
    int r = 0;
    for(; l; l = l->tail) r++;
    return r;
}

T_stm transDec(S_table venv, S_table tenv, A_dec d, Tr_level level){
    switch(d->kind) {
        case A_varDec: {
            struct expty e = transExp(venv, tenv, d->u.var.init, level);
            if(d->u.var.typ){
                Ty_ty t = S_look(tenv, d->u.var.typ);
                if(!ty_comp(actual_ty(t), e.ty)){
                    EM_error(d->pos, "value does not match declared type");
                    return NULL;
                }
            }
            Tr_access acc = Tr_allocLocal(level, TRUE);
            S_enter(venv, d->u.var.var, E_VarEntry(acc, e.ty));
            return Tr_varDec(acc, e.exp);
        }
        case A_typeDec: {
            A_nametyList tys = d->u.type;
            Ty_tyList l = NULL, end = NULL;
            for(; tys; tys = tys->tail){
                Ty_ty t = Ty_Name(tys->head->name, NULL);
                if(!end){
                    l = Ty_TyList(t, NULL);
                    end = l;
                }
                else{
                    end->tail = Ty_TyList(t, NULL);
                    end = end->tail;
                }
                S_enter(tenv, tys->head->name, t);
            }
            tys = d->u.type;
            for(; tys; tys = tys->tail){
                Ty_ty t = transTy(tenv, tys->head->ty);
                l->head->u.name.ty = t;
                l = l->tail;
            }
            return NULL;
        }
        case A_functionDec: {
            A_fundecList funs = d->u.function;
            for(; funs; funs = funs->tail){
                A_fundec f = funs->head;
                Ty_ty resultTy = Ty_Void();
                if(f->result) resultTy = S_look(tenv,f->result);
                Ty_tyList formalTys = makeFormalTyList(tenv,f->params);
                Temp_label name = Temp_newlabel();
                Tr_level new_level = Tr_newLevel(level, name, escapes(formalTys));
                S_enter(venv,f->name,E_FunEntry(new_level, name, formalTys, resultTy));
            }
            funs = d->u.function;
            for(; funs; funs = funs->tail){
                A_fundec f = funs->head;
                E_enventry e = S_look(venv, f->name);
                Tr_level new_level = e->u.fun.level;
                Ty_tyList formalTys = e->u.fun.formals;
                Ty_ty resultTy = e->u.fun.result;
                S_beginScope(venv);
                Tr_accessList accesses = Tr_formals(new_level);
                {A_fieldList l; Ty_tyList t; Tr_accessList a;
                    for(l=f->params, t=formalTys, a=accesses; l; l=l->tail, t=t->tail, a=a->tail)
                        S_enter(venv,l->head->name,E_VarEntry(a->head, t->head));
                }
                struct expty body = transExp(venv, tenv, f->body, new_level);
                if(!ty_comp(body.ty, actual_ty(resultTy))){
                    EM_error(d->pos, "function return type mismatch");
                    return NULL;
                }
                Tr_procEntryExit(new_level, body.exp, accesses);
                S_endScope(venv);
            }
            return NULL;
        }
    }
}

F_fragList SEM_transProg(A_exp exp){
    struct expty main = transExp(E_base_venv(), E_base_tenv(), exp, Tr_outermost());
    return F_FragList(F_ProcFrag(T_Exp(main.exp), Tr_outermost()), Tr_getResult());
}