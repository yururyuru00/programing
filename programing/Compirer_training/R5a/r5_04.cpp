#include <iostream>
#include "ast.h"
int main(void)
{

  Expression* v = new Exp_variable("n");
  Expression* c1 = new Exp_constant(Type_INT, 1);
  Expression* o1 = new Exp_operation2(Operator_PLUS, v, c1);
  Expression* c2 = new Exp_constant(Type_INT, 2);
  Expression* o2 = new Exp_operation2(Operator_MUL, o1, c2);
  o1->print(std::cout); std::cout<<std::endl;
  o2->print(std::cout); std::cout<<std::endl;
  return 0;

}
