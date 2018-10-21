//=====================================================================
//
//     testexec.cpp: mini-C プログラムのインタープリタのテスト
//
//            コンパイラ演習  2004 (c) 石浦菜岐佐
//
//=====================================================================

#include <iostream>
#include <string>
#include <list>
#include "ast.h"

int main(void)
{

  //------------------------------------------------------
  // Exp_function のテスト
  //------------------------------------------------------

  // getint();
  std::list<Expression*> arglist1;
  Expression* f_getint = new Exp_function("getint", arglist1);

  // getchar();
  std::list<Expression*> arglist2;
  Expression* f_getchar = new Exp_function("getchar", arglist2);

  // putint(5);
  Expression* c3 = new Exp_constant(Type_INT, 5);
  std::list<Expression*> arglist3;
  arglist3.push_back(c3);
  Expression* f_putint = new Exp_function("putint", arglist3);

  // putchar('U');
  Expression* c4 = new Exp_constant(Type_CHAR, 'U');
  std::list<Expression*> arglist4;
  arglist4.push_back(c4);
  Expression* f_putchar = new Exp_function("putchar", arglist4);

  // asum(n);
  Expression* v5 = new Exp_variable("n");
  std::list<Expression*> arglist5;
  arglist5.push_back(v5);
  Expression* f_asum = new Exp_function("asum", arglist5);

  std::map<std::string,Function*> func;
  std::map<std::string,int> gvar;
  std::map<std::string,int> lvar;
  func["asum"] = 0;  // ここが原因
  lvar["n"] = 7;
  std::cout << "n = " << lvar["n"] <<std::endl;
  std::cout << "ここで getint が呼ばれるので, 整数を入力" << std::endl;
  int rv1 = f_getint->run(func, gvar, lvar);
  std::cout << "getint() = " << rv1 <<std::endl;
  std::cout << "ここで getchar が呼ばれるので, 文字を入力" <<std::endl;
  int rv2 = f_getchar->run(func, gvar, lvar);
  std::cout << "getchar() = " << (char) rv2 <<std::endl;
  std::cout << "次に putint(5); が呼ばれる" <<std::endl;
  f_putint->run(func, gvar, lvar);
  std::cout << std::endl;
  std::cout << "次に putchar('U'); が呼ばれる" <<std::endl;
  f_putchar->run(func, gvar, lvar);
  std::cout << std::endl;
  std::cout << "最後に asum(n); が呼ばれる" <<std::endl;
  int rv_asum = f_asum->run(func, gvar, lvar);
  std::cout << "asum(n) = " << rv_asum <<std::endl;

  return 0;
};
