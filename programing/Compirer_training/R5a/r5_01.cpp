#include <iostream>
#include "ast.h"
int main(void)
{

  Expression* c1 = new Exp_constant(Type_INT, 7);
  Expression* c2 = new Exp_constant(Type_CHAR, 'x');
  c1->print(std::cout); std::cout<<std::endl;
  c2->print(std::cout); std::cout<<std::endl;

  return 0;

}
