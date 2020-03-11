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

//your functions here

F_fragList Tr_getResult(){
    return frags;
}