#include <iostream>
#include "ast.h"
int main(void)
{
  Expression* v = new Exp_variable("n");
  Expression* c1 = new Exp_constant(Type_INT, 1);
  Expression* o1 = new Exp_operation2(Operator_PLUS, v, c1);
  Expression* c2 = new Exp_constant(Type_INT, 2);
  Expression* o2 = new Exp_operation2(Operator_MUL, o1, c2);
  // テスト
  std::map<std::string,Function*> func;
  std::map<std::string,int> gvar;
  std::map<std::string,int> lvar;
  lvar["n"] = 31;
  std::cout << o1->run(func, gvar, lvar); std::cout<<std::endl;
  std::cout << o2->run(func, gvar, lvar); std::cout<<std::endl;

}
