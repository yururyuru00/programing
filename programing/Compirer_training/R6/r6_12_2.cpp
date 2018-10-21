#include <iostream>
#include "ast.h"
int main(void)
{
  std::list<Expression*> arglist;
  arglist.push_back(new Exp_constant(Type_INT, 5));
  Expression* exp_function_asum = new Exp_function("asum", arglist);
  std::map<std::string,Function*> func;
  std::map<std::string,int> gvar;
  std::map<std::string,int> lvar;
  func["asum"] = make_function_asum();
  int asum5 = exp_function_asum->run(func, gvar, lvar);
  std::cout << "asum(5) = " << asum5 <<std::endl;


  return 0;
}
