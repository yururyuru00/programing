#include <iostream>
#include "ast.h"
int main(void)
{
  Function* function_asum = make_function_asum(); // 前回の演習で作成したもの
  std::map<std::string,Function*> func;
  std::map<std::string,int> gvar;
  std::list<int> i_arglist;
  i_arglist.push_back(3);
  int r = function_asum->run(func, gvar, i_arglist);
  std::cout << r << std::endl;

  return 0;
}
