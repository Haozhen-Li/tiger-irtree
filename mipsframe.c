#include "util.h"
#include "temp.h"
#include "tree.h"
#include "frame.h"

const int F_wordSize = 8;
static Temp_temp FP = NULL;
static Temp_temp RV = NULL;

struct F_frame_
    {Temp_label name;
     F_accessList formals;
     int next_offset;
    };

struct F_access_
    {enum {inFrame, inReg} kind;
     union {
        int offset; /* InFrame */
        Temp_temp reg; /* InReg */
     } u;
    };
static F_access InFrame(int offset){
    F_access a = checked_malloc(sizeof(*a));
    a->kind = inFrame;
    a->u.offset = offset;
    return a;
}
static F_access InReg(Temp_temp reg){
    F_access a = checked_malloc(sizeof(*a));
    a->kind = inReg;
    a->u.reg = reg;
    return a;
}

F_accessList F_AccessList(F_access head, F_accessList tail){
    F_accessList l = checked_malloc(sizeof(*l));
    l->head = head;
    l->tail = tail;
    return l;
}

static F_accessList append(F_accessList list, F_access acc){
    if(!list) return F_AccessList(acc, NULL);
    F_accessList l = list;
    for(; l->tail; l = l->tail);
    l->tail = F_AccessList(acc, NULL);
    return list;
}

F_access F_allocLocal(F_frame f, bool escape){
    F_access acc;
    if(escape){
        acc = InFrame(f->next_offset);
        f->next_offset += F_wordSize;
    }
    else
        acc = InReg(Temp_newtemp());
    f->formals = append(f->formals, acc);
    return acc;
}

F_frame F_newFrame(Temp_label name, U_boolList formals){
    F_frame f = checked_malloc(sizeof(*f));
    f->name = name;
    for(; formals; formals = formals->tail)
        F_allocLocal(f, formals->head);
    return f;
}

Temp_label F_name(F_frame f){
    return f->name;
}

F_accessList F_formals(F_frame f){
    return f->formals;
}

Temp_temp F_FP(){
    if(!FP) FP = Temp_newtemp();
    return FP;
}
Temp_temp F_RV(){
    if(!RV) RV = Temp_newtemp();
    return RV;
}

T_exp F_Exp(F_access acc, T_exp framePtr){
    switch(acc->kind){
        case inFrame:
            return T_Mem(T_Binop(T_plus, framePtr, T_Const(acc->u.offset)));
        case inReg:
            return T_Temp(acc->u.reg);
    }
}

T_exp F_externalCall(string s, T_expList args){
    return T_Call(T_Name(Temp_namedlabel(s)), args);
}

T_stm F_procEntryExit1(F_frame frame, T_stm stm) {
    return stm;
}

F_frag F_StringFrag(Temp_label label, string str){
    F_frag f = checked_malloc(sizeof(*f));
    f->kind = F_stringFrag;
    f->u.stringg.label = label;
    f->u.stringg.str = str;
    return f;
}

F_frag F_ProcFrag(T_stm body, F_frame frame){
    F_frag f = checked_malloc(sizeof(*f));
    f->kind = F_procFrag;
    f->u.proc.body = body;
    f->u.proc.frame = frame;
    return f;
}

F_fragList F_FragList(F_frag head, F_fragList tail){
    F_fragList l = checked_malloc(sizeof(*l));
    l->head = head;
    l->tail = tail;
    return l;
}
