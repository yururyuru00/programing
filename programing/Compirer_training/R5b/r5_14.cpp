#include <iostream>
#include "ast.h"

int main()
{
  Variable* v1 = new Variable(Type_INT, "g");
  std::list<Variable*> varlist;
  varlist.push_back(v1);

  Function* f = make_function_asum();
  std::list<Function*> funclist;
  funclist.push_back(f);

  std::list<Variable*> arglist2;
  Variable* v2 = new Variable(Type_INT, "a");
  Exp_variable* v3 = new Exp_variable("g");
  std::list<Variable*> locallist2;
  locallist2.push_back(v2);
  std::list<Expression*> elist;
  elist.push_back(v3);
  Expression* e1 = new Exp_function("asum", elist);
  Statement* s1 = new St_assign(v3, e1);
  std::list<Statement*> slist;
  slist.push_back(s1);
  Statement* s2 = new St_list(slist);
  Function* main = new Function(Type_INT, "main", arglist2, locallist2, s2);

  Program* p = new Program(varlist, funclist, main);
  p->print(std::cout);

  return 0;
}
