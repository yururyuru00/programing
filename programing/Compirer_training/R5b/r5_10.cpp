#include <iostream>
#include "ast.h"

int main()
{
  Expression* e = new Exp_variable("s");
  Statement* s = new St_return(e);
  s->print(std::cout);
  return 0;
}
