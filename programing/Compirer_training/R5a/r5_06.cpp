#include <iostream>
#include "ast.h"
int main(void)
{
  Exp_variable* v1 = new Exp_variable("i");
  Expression* c1 = new Exp_constant(Type_INT, 0);
  Statement* s1 = new St_assign(v1,c1);
  s1->print(std::cout);
  s1->print(std::cout, 1);
  s1->print(std::cout, 2);

  return 0;

}
