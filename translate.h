#include <stddef.h>

typedef F_access Tr_access;
typedef F_accessList Tr_accessList;
Tr_accessList Tr_AccessList(Tr_access head, Tr_accessList tail);

typedef F_frame Tr_level;

Tr_level Tr_outermost(void);
Tr_level Tr_newLevel(Tr_level parent, Temp_label name, U_boolList formals);
Tr_accessList Tr_formals(Tr_level level);
Tr_access Tr_allocLocal(Tr_level level, bool escape);

T_exp Tr_simpleVar(Tr_access acc);
T_exp Tr_fieldVar(T_exp base, int offset);
T_exp Tr_subscriptVar(T_exp base, T_exp index);

T_exp Tr_binOp(A_oper op, T_exp left, T_exp right);
T_exp Tr_int(int val);
T_exp Tr_string(string str);
T_exp Tr_assign(T_exp left, T_exp right);
T_exp Tr_if(T_exp cond, T_exp tcase, T_exp fcase);
T_exp Tr_while(T_exp test, T_exp body);
Temp_temp Tr_start_record();
T_stm Tr_add_field(T_stm stm, int i, Temp_temp r, T_exp e);
T_exp Tr_finish_record(Temp_temp r, A_efieldList fields, T_stm body);
T_exp Tr_nil();
T_exp Tr_array(T_exp size, T_exp init);
T_exp Tr_call(Temp_label label, T_expList args);

T_stm Tr_varDec(Tr_access acc, T_exp exp);
void Tr_funDec(T_exp body);

void Tr_procEntryExit(Tr_level level, T_exp body, Tr_accessList formals);
F_fragList Tr_getResult(void);