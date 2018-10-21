#include <iostream>
#include "ast.h"
int main(void)
{
  Statement* s = make_while(); // 前回の演習で作成したもの
  std::map<std::string,Function*> func;
  std::map<std::string,int> gvar;
  std::map<std::string,int> lvar;
  lvar["i"] = -3;
  lvar["n"] = 3;
  lvar["s"] = 0;
  Return_t rd = s->run(func, gvar, lvar);
  std::cout << "i = " << lvar["i"] <<std::endl;
  std::cout << "n = " << lvar["n"] <<std::endl;
  std::cout << "s = " << lvar["s"] <<std::endl;

  return 0;
}
