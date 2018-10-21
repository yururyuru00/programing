//=====================================================================
//
//     ast.cpp: mini-C プログラムの抽象構文木 (実装)
//
//            コンパイラ実習  2004 (c) 平岡佑介, 石浦菜岐佐
//
//=====================================================================

#include "ast.h"

//---------------------------------------------------------------------
//   Type_string の実装
//---------------------------------------------------------------------
std::string Type_string(Type t)
{
  switch (t) {
    case Type_INT:  return "int";
    case Type_CHAR: return "char";
    default:        return "UNDEF";
  }
}

//---------------------------------------------------------------------
//   Opeartor_string の実装
//---------------------------------------------------------------------
std::string Operator_string(Operator o)
{
  switch (o) {
    case Operator_PLUS:  return "+";
    case Operator_MINUS: return "-";
    case Operator_MUL:   return "*";
    case Operator_DIV:   return "/";
    case Operator_MOD:   return "%";
    case Operator_LT:    return "<";
    case Operator_GT:    return ">";
    case Operator_LE:    return "<=";
    case Operator_GE:    return ">=";
    case Operator_NE:    return "!=";
    case Operator_EQ:    return "==";
    default:             return "???";
  }
}

static int tmp = 0;

//---------------------------------------------------------------------
//  tab(int)
//    インデントを行うための関数 (ast.cpp の中だけで用いる)
//    indent で指定された段数の 2 倍のスペースを返す
//---------------------------------------------------------------------
static std::string tab(int indent)
{
  std::string tab_ = "";
  for(int i=0; i<indent; i++){
    tab_ += "  ";
  }
  return tab_;
}

//------------------------
/*
Statement* make_if() {
// cond 部の木の生成
Expression* v1 = new Exp_variable("i");
Expression* c1 = new Exp_constant(Type_INT, 0);
Expression* cond = new Exp_operation2(Operator_LT, v1, c1);
// then 部の木の生成
Exp_variable* v2 = new Exp_variable("s");
Expression* e1 = new Exp_operation2(Operator_MINUS, v2, v1);
Statement* then = new St_assign(v2, e1);
// else 部の木の生成
Expression* e2 = new Exp_operation2(Operator_PLUS, v2, v1);
Statement* els = new St_assign(v2, e2); // else は予約語なので変数名には使えない

return new St_if(cond, then, els);
}

Statement* make_while () {
  Exp_variable* v1 = new Exp_variable("i");
  Expression* v2 = new Exp_variable("n");
  Expression* e1 = new Exp_operation2(Operator_LE, v1, v2);

  Expression* c = new Exp_constant(Type_INT, 1);
  Expression* e2 = new Exp_operation2(Operator_PLUS, v1, c);
  Statement* s2 = new St_assign(v1, e2);
  Statement* s1 = make_if();

  std::list<Statement*> slist;
  slist.push_back(s1);
  slist.push_back(s2);
  Statement* s3 = new St_list(slist);
  return new St_while(e1, s3);
}

Function* make_function_asum() {
  Variable* v1 = new Variable(Type_INT, "n");
  std::list<Variable*> arglist;
  arglist.push_back(v1);

  Variable* v2 = new Variable(Type_INT, "s");
  Variable* v3 = new Variable(Type_INT, "i");
  std::list<Variable*> locallist;
  locallist.push_back(v2);
  locallist.push_back(v3);

  Exp_variable* v4 = new Exp_variable("s");
  Expression* c1 = new Exp_constant(Type_INT, 0);
  Exp_variable* v5 = new Exp_variable("i");
  Exp_variable* v6 = new Exp_variable("n");
  Statement* s1 = new St_assign(v4, c1);
  Expression* o1 = new Exp_operation1(Operator_MINUS, v6);
  Statement* s2 = new St_assign(v5, o1);
  Statement* s3 = make_while();
  Statement* s4 = new St_return(v4);

  std::list<Statement*> bodylist;
  bodylist.push_back(s1);
  bodylist.push_back(s2);
  bodylist.push_back(s3);
  bodylist.push_back(s4);
  Statement* s5 = new St_list(bodylist);

  return new Function(Type_INT, "asum", arglist, locallist, s5);

}

Function* make_function_main() {
  Variable* v1 = new Variable(Type_INT, "a");
  Exp_variable* v3 = new Exp_variable("a");

  Exp_variable* v2 = new Exp_variable("g");
  Statement* s1 = new St_assign(v2, new Exp_constant(Type_INT, 3));

  std::list<Expression*> args;
  args.push_back(v2);
  Expression* e1 = new Exp_function("asum", args);
  Statement* s2 = new St_assign(v3, e1);

  std::list<Expression*> args2;
  args2.push_back(v3);
  Statement* s3 = new St_function("putint", args2);

  std::list<Statement*> stlist;
  stlist.push_back(s1);
  stlist.push_back(s2);
  stlist.push_back(s3);
  Statement* s4 = new St_list(stlist);

  std::list<Variable*> main_args;
  std::list<Variable*> main_local_vars;
  main_local_vars.push_back(v1);

  return new Function(Type_INT, "main", main_args,
   main_local_vars, s4);
}
*/
//---------------------------------------------------------------------
//   Exp_constant::print の実装
//---------------------------------------------------------------------
void Exp_constant::print(std::ostream& os) const
{
  switch(type()) {
    case Type_INT: os << value(); break;
    case Type_CHAR: {
      os << '\'';
      if (value()=='\n') {
        os << '\\';
        os << 'n';
      }
      else if (value()=='\t') {
        os << '\\';
        os << 't';
      }
      else if (value()=='\\') {
        os << '\\';
        os << '\\';
      }
      else {
        os << (char) value();
      }
      os << '\'';
      break;
    }
    default: assert(0);
  }
}
//------------------------------------------------------------
void Exp_variable::print(std::ostream& os) const {
  os << name();
}

int Exp_variable::run(
  std::map<std::string,Function*>& func,
  std::map<std::string,int>& gvar,
  std::map<std::string,int>& lvar
) const {
    std::map<std::string,int>::const_iterator p;
    if ((p=lvar.find(name()))!=lvar.end()) {
      return p->second;
    }
    else if ((p=gvar.find(name()))!=gvar.end()) {
      return p->second;
    }
    else {
      std::cout << "そのような変数は宣言されていません";
      return 0;
    }
}

//------------------------------------------------------------
void Exp_operation1::print(std::ostream& os) const {
  os << "(" << Operator_string(operation());
  if (operand()) {
    operand()->print(os);
  }
  else {
    os << "UNDEF";
  }
  os << ")";
}


int Exp_operation1::run(
  std::map<std::string,Function*>& func,
  std::map<std::string,int>& gvar,
  std::map<std::string,int>& lvar
) const {
  if(operand()) {
    switch (operation()) {
      case Operator_PLUS: return +operand()->run(func, gvar, lvar); break;
      case Operator_MINUS: return -operand()->run(func, gvar, lvar); break;
      default: std::cout << "UNDEF"; break;
    }
  }
  else {
    std::cout << "オペランドが定義されていない";
  }
}

//-------------------------------------------------------------
void Exp_operation2::print(std::ostream& os) const {
  os << "(";
  if(operand1()) operand1()->print(os);
  else os << "UNDEF";

  os << Operator_string(operation());

  if(operand2()) operand2()->print(os);
  else os << "UNDEF";

  os << ")";
}

int Exp_operation2::run(
  std::map<std::string,Function*>& func,
  std::map<std::string,int>& gvar,
  std::map<std::string,int>& lvar
) const {
  if(operand1() && operand2()) {
    switch (operation()) {
      case Operator_PLUS: return operand1()->run(func, gvar, lvar)
        + operand2()->run(func, gvar, lvar); break;
      case Operator_MINUS:return operand1()->run(func, gvar, lvar)
        - operand2()->run(func, gvar, lvar); break;
      case Operator_MUL: return operand1()->run(func, gvar, lvar)
        * operand2()->run(func, gvar, lvar); break;
      case Operator_DIV: return operand1()->run(func, gvar, lvar)
        / operand2()->run(func, gvar, lvar); break;
      case Operator_MOD: return operand1()->run(func, gvar, lvar)
        % operand2()->run(func, gvar, lvar); break;
      case Operator_LT: return operand1()->run(func, gvar, lvar)
        < operand2()->run(func, gvar, lvar); break;
      case Operator_GT: return operand1()->run(func, gvar, lvar)
        > operand2()->run(func, gvar, lvar); break;
      case Operator_LE: return operand1()->run(func, gvar, lvar)
        <= operand2()->run(func, gvar, lvar); break;
      case Operator_GE: return operand1()->run(func, gvar, lvar)
        >= operand2()->run(func, gvar, lvar); break;
      case Operator_NE: return operand1()->run(func, gvar, lvar)
        != operand2()->run(func, gvar, lvar); break;
      case Operator_EQ: return operand1()->run(func, gvar, lvar)
        == operand2()->run(func, gvar, lvar); break;
      default: std::cout << "UNDEF"; break;
    }
  }
}
//-----------------------------------------------------------------
Exp_function::~Exp_function() {
  for (std::list<Expression*>::const_iterator it = args_.begin();
  it != args_.end(); it++) {
    delete *it;
  }
}

void Exp_function::print(std::ostream& os) const {

  os << name();
  os << "(";

  int c = 1;  args_.size();
  for(std::list<Expression*>::const_iterator it = args_.begin();
  it != args_.end(); it++) {
    (*it)->print(os);
    if(c<args_.size()) {os << ", "; c++;}
    else ;
  }

  os << ")";
}

int Exp_function::run(
std::map<std::string,Function*>& func,
std::map<std::string,int>& gvar,
std::map<std::string,int>& lvar
) const
{
  std::list<int> i_args;
  std::map<std::string,int>::const_iterator p;
  for(std::list<Expression*>::const_iterator it = args_.begin();
  it != args_.end(); it++) {
    i_args.push_back((*it)->run(func, gvar, lvar));
  }

  if(name()=="getint") {
    int i;
    std::cin >> i;
    return i;
  }
  else if(name()=="getchar") {
    char c;
    std::cin >> c;
    return c;
  }
  else if(name()=="putint") {
    int i = i_args.front();
    std::cout << i;
    return 0;
  }
  else if(name()=="putchar") {
    char i = i_args.front();
    std::cout << i;
    return 0;
  }
  else {
    std::map<std::string,Function*>::const_iterator p;
    if ((p=func.find(name()))!=func.end()) {
      Function* f = p->second; //ここで0代入
      return f->run(func,gvar,i_args); // ここでfunction関数に引数リストを渡している
    }
    else {
      std::cout << "そのような関数名は宣言されていません";
      return 0;
    }

}
}

//-------------------------------------------------------------------
void St_assign::print(std::ostream& os, int indent) const {
  os << tab(indent); // インデント (1 段につきスペース 2 個) をつける
  if (lhs()) { // 左辺が NULL でなければ
    lhs()->print(os); // 左辺を表示
  }
  else {
    os << "UNDEF"; // 左辺が NULL なら取り敢えず UNDEF と表示
  }
  os << " = ";
  if (rhs()) { // 右辺が NULL でなければ
    rhs()->print(os); // 右辺を表示
  }
  else {
    os << "UNDEF";
  }
  os << ";" << std::endl;
}

Return_t St_assign::run(
  std::map<std::string,Function*>& func,
  std::map<std::string,int>& gvar,
  std::map<std::string,int>& lvar
) const {
  assert(lhs());
  assert(rhs());

  int i_rhs = rhs()->run(func, gvar, lvar);

  std::map<std::string,int>::iterator p;
  if ((p=lvar.find(lhs()->name()))!=lvar.end()) {
    p->second = i_rhs;
  }
  else if ((p=gvar.find(lhs()->name()))!=gvar.end()) {
    p->second = i_rhs;
  }
  else {
    std::cout << "そのような変数は宣言されていません";
  }

  return Return_t(false, 0);
}

//-----------------------------------------------------------------
St_list::~St_list() {
  for(std::list<Statement*>::const_iterator it = statement_.begin();
  it != statement_.end(); it++) {
    delete *it;
  }
}

void St_list::print(std::ostream& os, int indent) const {
  indent++;

  for(std::list<Statement*>::const_iterator it = statement_.begin();
  it != statement_.end(); it++) {
    (*it)->print(os, indent);
  }
}

Return_t St_list::run(
  std::map<std::string,Function*>& func,
  std::map<std::string,int>& gvar,
  std::map<std::string,int>& lvar
) const {
  for(std::list<Statement*>::const_iterator it = statements().begin();
  it!= statements().end(); it++) {
    assert(*it);
    Return_t rd = (*it)->run(func, gvar, lvar);
    if (rd.val_is_returned) return rd;
  }
  return Return_t(false, 0);
}

//------------------------------------------------------------------
void St_if::print(std::ostream& os, int indent) const {
  os << tab(indent);
  os << "if";
  if(condition()) condition()->print(std::cout);
  else os << "UNDEF";
  os << "{" << std::endl;
  indent++;

  if(then_part()) then_part()->print(std::cout, indent);
  else os << "UNDEF";
  indent--;
  os << tab(indent);
  os << "}" << std::endl;

  os << tab(indent) << "else {" << std::endl;
  indent++;

  if(else_part()) else_part()->print(std::cout, indent);
  indent--;
  os << tab(indent);
  os << "}" << std::endl;
}

Return_t St_if::run(
  std::map<std::string,Function*>& func,
  std::map<std::string,int>& gvar,
  std::map<std::string,int>& lvar
) const {
  Return_t rd;
  if(condition()->run(func, gvar, lvar)!=0) {
    if(then_part()) {
      rd = then_part()->run(func, gvar, lvar);
      if(rd.val_is_returned) return rd;
    }
  }
  else {
    if(else_part()) {
      rd = else_part()->run(func, gvar, lvar);
      if(rd.val_is_returned) return rd;
    }
  }
  return Return_t(false, 0);
}
//-----------------------------------------------------------
void St_while::print(std::ostream& os, int indent) const {
  os << tab(indent);
  os << "while";
  if(condition()) condition()->print(std::cout);
  else os << "UNDEF";
  os << "{" << std::endl;
  indent++;

  body()->print(os, indent);

  indent--;
  os << tab(indent);
  os << "}" << std::endl;
}

Return_t St_while::run(
    std::map<std::string,Function*>& func,
    std::map<std::string,int>& gvar,
    std::map<std::string,int>& lvar
  ) const {
    Return_t rd;
    while(condition()->run(func, gvar, lvar)!=0) {
      rd = body()->run(func, gvar, lvar);
      if(rd.val_is_returned) return rd;
    }
    return Return_t(false, 0);
  }

//-------------------------------------------------------------------
void St_return::print(std::ostream& os, int indent) const {
  os << tab(indent);
  os << "return ";

  if(value()) value()->print(os);
  else os << "UNDEF";

  os << ";" << std::endl;
}

Return_t St_return::run(
  std::map<std::string,Function*>& func,
  std::map<std::string,int>& gvar,
  std::map<std::string,int>& lvar
) const {
  assert(value());
  int rv = value()->run(func, gvar, lvar);
  return Return_t(true, rv);
}
//---------------------------------------------------------------------
void St_function::print(std::ostream& os, int indent) const {
  os << tab(indent);
  function_.print(os);
  os << ";" << std::endl;
}

Return_t St_function::run(
  std::map<std::string,Function*>& func,
  std::map<std::string,int>& gvar,
  std::map<std::string,int>& lvar
) const {
  function_.run(func, gvar, lvar);
  return Return_t(false, 0);
}
//--------------------------------------------------------------------
void Variable::print(std::ostream& os) const {
  os << Type_string(type()) + " ";
  os << name();
}
//---------------------------------------------------------------------
Function::~Function() {
  for(std::list<Variable*>::const_iterator it = args().begin();
  it != args().end(); it++) {
    delete *it;
  }
  for(std::list<Variable*>::const_iterator it = local_vars().begin();
  it != local_vars().end(); it++) {
    delete *it;
  }
  delete body();

}

void Function::print(std::ostream& os) const {
  os << Type_string(type()) << " ";
  os << name() << "(";

  for(std::list<Variable*>::const_iterator it = args().begin();
  it != args().end(); it++) {
    (*it)->print(os);
  }

  os << ")" << std::endl;
  os << "{" << std::endl;

  for(std::list<Variable*>::const_iterator it = local_vars().begin();
  it != local_vars().end(); it++) {
    os << tab(1);
    (*it)->print(os);
    os << ";" << std::endl;
  }
  os << std::endl;

  body()->print(os, 0);

  os << "}" << std::endl;
}

int Function::run(
std::map<std::string,Function*>& func,
std::map<std::string,int>& gvar,
std::list<int>& i_args
) const
{
return i_args.front(); // 仮の実装
}
//--------------------------------------------------------------------
Program::~Program() {
  for(std::list<Variable*>::const_iterator it = vars().begin();
  it != vars().end(); it++) {
    delete *it;
  }
  for(std::list<Function*>::const_iterator it = funcs().begin();
  it != funcs().end(); it++) {
    delete *it;
  }
  delete main_;
}

void Program::print(std::ostream& os) const {
  for(std::list<Variable*>::const_iterator it = vars().begin();
  it != vars().end(); it++) {
    os << tab(1);
    (*it)->print(os);
    os << ";" << std::endl;
  }

  for(std::list<Function*>::const_iterator it = funcs().begin();
  it != funcs().end(); it++) {
    os << tab(1);
    (*it)->print(os);
  }

  main()->print(os);
}

int Program::run() const {

  std::map<std::string,int> gvar;
  for(std::list<Variable*>::const_iterator it = vars().begin();
  it!= vars().end(); it++) {
    gvar[(*it)->name()] = 0;
  }

  std::map<std::string,Function*> func;
  for(std::list<Function*>::const_iterator it = funcs().begin();
  it!= funcs().end(); it++) {
    if((*it)) func[(*it)->name()] = (*it);
  }

  std::list<int> iargs;
  int v = main()->run(func, gvar, iargs);
  return v;

}
