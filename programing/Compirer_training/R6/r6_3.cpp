#include <iostream>
#include "ast.h"
int main(void)
{
  Expression* v = new Exp_variable("n");
  Expression* o = new Exp_operation1(Operator_MINUS, v);
// テスト
  std::map<std::string,Function*> func;
  std::map<std::string,int> gvar;
  std::map<std::string,int> lvar;
  lvar["n"] = 31;
  std::cout << o->run(func, gvar, lvar); std::cout<<std::endl;


  return 0;

}
