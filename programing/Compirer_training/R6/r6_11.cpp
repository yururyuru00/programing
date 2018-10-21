#include <iostream>
#include "ast.h"
int main(void)
{
  std::list<Expression*> arglist;
  arglist.push_back(new Exp_variable("a"));
  Statement* s = new St_function("putint", arglist);
  std::map<std::string,Function*> func;
  std::map<std::string,int> gvar;
  std::map<std::string,int> lvar;
  lvar["a"] = -3249;
  Return_t rd = s->run(func, gvar, lvar);

  return 0;
}
