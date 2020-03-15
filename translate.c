/*
    Haozhen Li
    Project 4 (Late)
    CS 473 2pm section
    Prof. Mansky
*/


#include "util.h"
#include "symbol.h"
#include "temp.h"
#include "tree.h"
#include "frame.h"
#include "absyn.h"
#include "translate.h"

F_fragList frags = NULL;
static Tr_level outermost;

Tr_level Tr_outermost(){
    if(!outermost) outermost = F_newFrame(Temp_namedlabel("main"), NULL);
    return outermost;
}

Tr_accessList Tr_AccessList(Tr_access head, Tr_accessList tail){
    return F_AccessList(head, tail);
}

Tr_access Tr_allocLocal(Tr_level level, bool escape){
    return F_allocLocal(level, escape);
}


Tr_level Tr_newLevel(Tr_level parent, Temp_label name, U_boolList formals){
    return F_newFrame(name, formals);
}

Tr_accessList Tr_formals(Tr_level level){
    return F_formals(level);
}

// var functions

T_exp Tr_simpleVar(Tr_access acc){
    return F_Exp(acc, T_Temp(F_FP()));
}
/*
T_exp F_Exp(F_access acc, T_exp framePtr){
    switch(acc->kind){
        case inFrame:
            return T_Mem(T_Binop(T_plus, framePtr, T_Const(acc->u.offset)));
        case inReg:
            return T_Temp(acc->u.reg);
    }
}
*/


// assuming that the offset here means actual address offset
// so no need to do multiplication w/ F_wordsize to get actual address offset
T_exp Tr_fieldVar(T_exp base, int offset){
    return T_Mem(
        T_Binop( T_plus, base, T_Const(offset) )
    );
}

// need to calculate actual offset from (index*F_wordSize)
T_exp Tr_subscriptVar(T_exp base, T_exp index){
    return T_Mem(
        T_Binop( T_plus, base, 
            T_Binop(T_mul, index, T_Const(F_wordSize))
        )
    );
}

T_exp Tr_binOp(A_oper op, T_exp left, T_exp right){
    Temp_label t = Temp_newlabel();
    Temp_label f = Temp_newlabel();
    Temp_temp temp = Temp_newtemp();
    switch(op){
        // simple translation
        case A_plusOp: return T_Binop(T_plus, left, right); 
        case A_minusOp: return T_Binop(T_minus, left, right);
        case A_timesOp: return T_Binop(T_mul, left, right);
        case A_divideOp: return T_Binop(T_div, left, right);
        // conditional operators are implemented using eseq similar to
        // instrction on hw3 1)e
        case A_eqOp: 
            return T_Eseq(
                T_Seq(T_Cjump(T_eq, left, right, t, f), T_Seq(
                    T_Seq( T_Label(t), T_Move( T_Temp(temp), T_Const(1)) ),
                    T_Seq( T_Label(f), T_Move( T_Temp(temp), T_Const(0)) )
                )), 
                T_Temp(temp)
            );
        case A_neqOp:
            return T_Eseq(
                T_Seq(T_Cjump(T_ne, left, right, t, f), T_Seq(
                    T_Seq( T_Label(t), T_Move( T_Temp(temp), T_Const(1)) ),
                    T_Seq( T_Label(f), T_Move( T_Temp(temp), T_Const(0)) )
                )), 
                T_Temp(temp)
            );
        case A_ltOp:
            return T_Eseq(
                T_Seq(T_Cjump(T_lt, left, right, t, f), T_Seq(
                    T_Seq( T_Label(t), T_Move( T_Temp(temp), T_Const(1)) ),
                    T_Seq( T_Label(f), T_Move( T_Temp(temp), T_Const(0)) )
                )), 
                T_Temp(temp)
            );
        case A_leOp:
            return T_Eseq(
                T_Seq(T_Cjump(T_le, left, right, t, f), T_Seq(
                    T_Seq( T_Label(t), T_Move( T_Temp(temp), T_Const(1)) ),
                    T_Seq( T_Label(f), T_Move( T_Temp(temp), T_Const(0)) )
                )), 
                T_Temp(temp)
            );
        case A_gtOp:
            return T_Eseq(
                T_Seq(T_Cjump(T_gt, left, right, t, f), T_Seq(
                    T_Seq( T_Label(t), T_Move( T_Temp(temp), T_Const(1)) ),
                    T_Seq( T_Label(f), T_Move( T_Temp(temp), T_Const(0)) )
                )), 
                T_Temp(temp)
            );
        case A_geOp:
            return T_Eseq(
                T_Seq(T_Cjump(T_ge, left, right, t, f), T_Seq(
                    T_Seq( T_Label(t), T_Move( T_Temp(temp), T_Const(1)) ),
                    T_Seq( T_Label(f), T_Move( T_Temp(temp), T_Const(0)) )
                )), 
                T_Temp(temp)
            );
    }
}// done Tr_binOp

T_exp Tr_int(int val){
    // shouldn't be more complicated then this
    return T_Const(val);
}

T_exp Tr_string(string str){
    // create new label
    Temp_label label = Temp_newlabel();
    // assign string frag to the label
    F_StringFrag(label, str);
    // return the string as label tree
    return T_Name(label);
}

// assign using move with eseq and const 0 as filler to get T_exp ret type
T_exp Tr_assign(T_exp left, T_exp right){
    return T_Eseq(
        T_Move(left, right),
        T_Const(0)
    );
}

// similar stragety to Tr_Binop, use cjump to pass 1/0 to temp as result
T_exp Tr_if(T_exp cond, T_exp tcase, T_exp fcase){
    Temp_label t = Temp_newlabel();
    Temp_label f = Temp_newlabel();
    Temp_temp temp = Temp_newtemp();
    return T_Eseq(
        T_Seq(T_Cjump(T_ne, T_Const(0), fcase, t, f), T_Seq(
            T_Seq( T_Label(t), T_Move( T_Temp(temp), T_Const(1)) ),
            T_Seq( T_Label(f), T_Move( T_Temp(temp), T_Const(0)) )
        )), 
        T_Temp(temp)
    );
}

T_exp Tr_while(T_exp test, T_exp body){

}

Temp_temp Tr_start_record(){

}

T_stm Tr_add_field(T_stm stm, int i, Temp_temp r, T_exp e){

}

T_exp Tr_finish_record(Temp_temp r, A_efieldList fields, T_stm body){
    
}

T_exp Tr_nil(){
    // from piazza @127:
    // "You can represent null-ness in the same way it's represented in C: as the integer 0."
    return T_Const(0);
}

T_exp Tr_array(T_exp size, T_exp init){

}

T_exp Tr_call(Temp_label label, T_expList args){

}



T_stm Tr_varDec(Tr_access acc, T_exp exp){
    T_exp framePtr = T_Temp(F_FP()); 
    // assign declearation(exp) to variable(acc)
    return T_Move( F_Exp(acc, framePtr), T_exp );
}

// void Tr_funDec(T_exp body);
// removed as instructed on piazza @137

void Tr_procEntryExit(Tr_level level, T_exp body, Tr_accessList formals){}



F_fragList Tr_getResult(){
    return frags;
}
