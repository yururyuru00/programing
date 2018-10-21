

#include <iostream>
#include "ast.h"
int main(void)
{
  Expression* v_a = new Exp_variable("a");
  Expression* v_n = new Exp_variable("n");
  Expression* v_x = new Exp_variable("x");
  Expression* v_p = new Exp_variable("p");
  // 3 つの表の宣言
  std::map<std::string,Function*> func;
  std::map<std::string,int> gvar;
  std::map<std::string,int> lvar;
  // 変数の値を設定
  lvar["a"] = 4;
  lvar["x"] = 2000;
  gvar["x"] = -95;
  gvar["n"] = 10;
  // 実行と表示
  std::cout << v_a->run(func,gvar,lvar); std::cout<<std::endl;
  std::cout << v_n->run(func,gvar,lvar); std::cout<<std::endl;
  std::cout << v_x->run(func,gvar,lvar); std::cout<<std::endl;
  std::cout << v_p->run(func,gvar,lvar); std::cout<<std::endl;

  return 0;

}
