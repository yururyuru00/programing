//*********************************************************************
//   factor.mc の ast を作るテスト用プログラム
//*********************************************************************
#include <iostream>
#include <string>
#include <list>
#include "ast.h"


// factor 中の while 文中の if 文
Statement* make_if()
{
  // n % d == 0
  Expression* v_1_n = new Exp_variable("n");
  Expression* v_1_d = new Exp_variable("d");
  Expression* e_1_1 = new Exp_operation2(Operator_MOD, v_1_n, v_1_d);
  Expression* c_1 =   new Exp_constant(Type_INT, 0);
  Expression* cond  = new Exp_operation2(Operator_EQ, e_1_1, c_1);

  // putint(d);
  Expression* v_2 = new Exp_variable("d");
  std::list<Expression*> arglist2;
  arglist2.push_back(v_2);
  Statement* s_2 = new St_function("putint",arglist2);

  // putchar(separator);
  Expression* v_3 = new Exp_variable("separator");
  std::list<Expression*> arglist3;
  arglist3.push_back(v_3);
  Statement* s_3 = new St_function("putchar",arglist3);

  // n = n / d;
  Expression* v_4_1 = new Exp_variable("n");
  Expression* v_4_2 = new Exp_variable("d");
  Expression* e_4 = new Exp_operation2(Operator_DIV, v_4_1, v_4_2);
  Exp_variable* v_4_3 = new Exp_variable("n");
  Statement* s_4 = new St_assign(v_4_3, e_4);

  // then
  std::list<Statement*> slist1;
  slist1.push_back(s_2);
  slist1.push_back(s_3);
  slist1.push_back(s_4);
  Statement* then = new St_list(slist1);

  // d = d + 1;
  Expression* v_5_1 = new Exp_variable("d");
  Expression* c_5 = new Exp_constant(Type_INT, 1);
  Expression* e_5 = new Exp_operation2(Operator_PLUS, v_5_1, c_5);
  Exp_variable* v_5_2 = new Exp_variable("d");
  Statement* s_5 = new St_assign(v_5_2, e_5);

  // else
  std::list<Statement*> slist2;
  slist2.push_back(s_5);
  Statement* else_ = new St_list(slist2);

  return new St_if(cond,then,else_);
}


Statement* make_while()
{
  // d * d <= n
  Expression* v_1_1 = new Exp_variable("d");
  Expression* v_1_2 = new Exp_variable("d");
  Expression* e_1_1 = new Exp_operation2(Operator_MUL, v_1_1, v_1_2);
  Expression* v_1_3 = new Exp_variable("n");
  Expression* cond  = new Exp_operation2(Operator_LE, e_1_1, v_1_3);
  Statement* body = make_if();
  return new St_while(cond,body);
}


Function* make_factor()
{
  // int n;
  Variable* v_n = new Variable(Type_INT, "n");

  // int d;
  Variable* v_d = new Variable(Type_INT, "d");

  // d = 2;
  Exp_variable* v_1 = new Exp_variable("d");
  Expression* c_1 = new Exp_constant(Type_INT, 2);
  Statement* s_1 = new St_assign(v_1, c_1);

  // while
  Statement* s_2 = make_while();

  // putint(n);
  Expression* v_3 = new Exp_variable("n");
  std::list<Expression*> arglist3;
  arglist3.push_back(v_3);
  Statement* s_3 = new St_function("putint",arglist3);

  // putchar('\n');
  Expression* c_4 = new Exp_constant(Type_CHAR, '\n');
  std::list<Expression*> arglist4;
  arglist4.push_back(c_4);
  Statement* s_4 = new St_function("putchar",arglist4);

  std::list<Variable*> arg_list;
  arg_list.push_back(v_n);
  std::list<Variable*> lv_list;
  lv_list.push_back(v_d);
  std::list<Statement*> st_list;
  st_list.push_back(s_1);
  st_list.push_back(s_2);
  st_list.push_back(s_3);
  st_list.push_back(s_4);
  St_list* sl = new St_list(st_list);
  return new Function(Type_INT, "factor", arg_list, lv_list, sl);
}


Function* make_main()
{
  // int n;
  Variable* v_n = new Variable(Type_INT, "n");

  // putchar('n');
  Expression* c_1 = new Exp_constant(Type_CHAR, 'n');
  std::list<Expression*> arglist1;
  arglist1.push_back(c_1);
  Statement* s_1 = new St_function("putchar",arglist1);

  // putchar('=');
  Expression* c_2 = new Exp_constant(Type_CHAR, '=');
  std::list<Expression*> arglist2;
  arglist2.push_back(c_2);
  Statement* s_2 = new St_function("putchar",arglist2);

  // n = getint();
  Exp_variable* v_3 = new Exp_variable("n");
  std::list<Expression*> arglist3;
  Expression* f_3 = new Exp_function("getint",arglist3);
  Statement * s_3 = new St_assign(v_3, f_3);

  // separator = '*';
  Exp_variable* v_4 = new Exp_variable("separator");
  Expression* c_4 = new Exp_constant(Type_CHAR,'*');
  Statement * s_4 = new St_assign(v_4, c_4);

  // function(n);
  Exp_variable* v_5 = new Exp_variable("n");  
  std::list<Expression*> arglist5;
  arglist5.push_back(v_5);
  Statement* s_5 = new St_function("factor",arglist5);

  std::list<Variable*> arg_list;
  std::list<Variable*> lv_list;
  lv_list.push_back(v_n);
  std::list<Statement*> st_list;
  st_list.push_back(s_1);
  st_list.push_back(s_2);
  st_list.push_back(s_3);
  st_list.push_back(s_4);
  st_list.push_back(s_5);
  St_list* sl = new St_list(st_list);
  return new Function(Type_INT, "main", arg_list, lv_list, sl);
}


int main(void)
{
  // char separator;   
  Variable* v = new Variable(Type_CHAR, "separator");

  // factor
  Function* f_factor = make_factor();

  // main
  Function* f_main = make_main();

  // variable declaration
  std::list<Variable*> vlist;
  vlist.push_back(v);

  // function declaration
  std::list<Function*> flist;
  flist.push_back(f_factor);

  Program* prog = new Program(vlist, flist, f_main);
  prog->print(std::cout);

  return 0;
};


