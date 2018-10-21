#include <iostream>
#include "ast.h"

int main()
{
  Exp_variable* v1 = new Exp_variable("a");
  Exp_variable* v2 = new Exp_variable("x");
  Expression* e = new Exp_operation2(Operator_PLUS, v1, v2);
  std::list<Expression*> arglist;
  arglist.push_back(v1);
  arglist.push_back(e);

  Statement* s = new St_function("putint", arglist);
  s->print(std::cout);
  return 0;
}
