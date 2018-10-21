#include <iostream>
#include "ast.h"
int main(void)
{
  Expression* v1 = new Exp_variable("a");
  Expression* v2 = new Exp_variable("b");
  std::list<Expression*> arglist;
  arglist.push_back(v1);
  arglist.push_back(v2);
  Expression* f = new Exp_function("gcd", arglist);
  f->print(std::cout); std::cout<<std::endl;

  return 0;

}
