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

Statement* make_if(void)
{
  // cond: i<0
  Expression* cond = new Exp_operation2(
    Operator_LT, 
    new Exp_variable("i"), 
    new Exp_constant(Type_INT,0)
  );

  // then: s = s - i;
  Statement* then = new St_assign(
    new Exp_variable("s"),
    new Exp_operation2(
      Operator_MINUS, 
      new Exp_variable("s"), 
      new Exp_variable("i")
    )
  );

  // else s = s + i;
  Statement* els = new St_assign(
    new Exp_variable("s"),
    new Exp_operation2(
      Operator_PLUS, 
      new Exp_variable("s"), 
      new Exp_variable("i")
    )
  );

  Statement* els2 = new St_return(new Exp_variable("s"));

  return new St_if(cond,then,els2);

}

// 5.09 のまま
Statement* make_while()
{
  // cond: i<=n
  Expression* v11 = new Exp_variable("i");
  Expression* v12 = new Exp_variable("n");
  Expression* cond = new Exp_operation2(Operator_LE, v11, v12);

  // body
  std::list<Statement*> slist;
  // if 文
  Statement* b1 = make_if();
  slist.push_back(b1);
  // i = i + 1;
  Expression* v21 = new Exp_variable("i");
  Expression* c2 = new Exp_constant(Type_INT,1);
  Expression* e2 = new Exp_operation2(Operator_PLUS, v21, c2);
  Exp_variable* v22 = new Exp_variable("i");
  Statement* b2 = new St_assign(v22, e2);
  slist.push_back(b2);
  Statement* body = new St_list(slist);

  // while 文全体
  Statement* s = new St_while(cond, body);
  return s;
}

int main(void)
{

  //------------------------------------------------------
  // St_return のテスト
  //------------------------------------------------------
  Statement* s = make_while();

  std::map<std::string,Function*> func;
  std::map<std::string,int> gvar; 
  std::map<std::string,int> lvar; 
  lvar["i"] = -3;
  lvar["n"] =  3;
  lvar["s"] =  0;
  std::cout << "i = " << lvar["i"] <<std::endl;
  std::cout << "n = " << lvar["n"] <<std::endl;
  std::cout << "s = " << lvar["s"] <<std::endl;
  Return_t ri = s->run(func, gvar, lvar);
  std::cout << "rd.val_is_returned = " << ri.val_is_returned <<std::endl;
  std::cout << "rd.return_val = " << ri.return_val <<std::endl;

  return 0;
};
