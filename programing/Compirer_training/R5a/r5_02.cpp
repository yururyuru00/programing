#include <iostream>
#include "ast.h"
int main(void)
{

  Expression* v = new Exp_variable("n");
  v->print(std::cout); std::cout<<std::endl;

  return 0;

}
