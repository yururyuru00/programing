#include <iostream>
#include "ast.h"
int main(void)
{
  // 5.07 のまま
  // s = 0;
  Statement* s = make_if(); // 前回の演習で作成したもの
  std::map<std::string,Function*> func;
  std::map<std::string,int> gvar;
  std::map<std::string,int> lvar;
  // 真の場合
  lvar["i"] = -5;
  lvar["s"] = 10;
  Return_t rd1 = s->run(func, gvar, lvar);
  std::cout << "s = " << lvar["s"] <<std::endl;
  // 偽の場合
  lvar["i"] = 7;
  lvar["s"] = 10;
  Return_t rd0 = s->run(func, gvar, lvar);
  std::cout << "s = " << lvar["s"] <<std::endl;

  return 0;
}
