#include <iostream>
#include "ast.h"
int main(void)
{
  // s = 0;
Exp_variable* v1 = new Exp_variable("s");
Expression* c1 = new Exp_constant(Type_INT, 0);
Statement* s1 = new St_assign(v1,c1);
// i = -n;
Exp_variable* v2 = new Exp_variable("i");
Exp_variable* v3 = new Exp_variable("n");
Expression* e1 = new Exp_operation1(Operator_MINUS, v3);
Statement* s2 = new St_assign(v2,e1);
// St list を構成
std::list<Statement*> slist;
slist.push_back(s1);
slist.push_back(s2);
Statement* s3 = new St_list(slist);
// 表示
s3->print(std::cout,1);


  return 0;

}
