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
Statement* make_if() {
// cond 部の木の生成
Expression* v1 = new Exp_variable("i");
Expression* c1 = new Exp_constant(Type_INT, 0);
Expression* cond = Exp_operation2(Operator_LT, v, c1);
// then 部の木の生成
Expression* v2 = new Exp_variable("s");
Expression* e = new Exp_operation2(Operator_MINUS, v2, v1);
Statement* then = St_assign(v2, e);
// else 部の木の生成
Expression* e = new Exp_operation2(Operator_PLUS, v2, v1);
Statement* els = St_assign(v2, e); // else は予約語なので変数名には使えない

return new St if(cond, then, els);
}


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
//-----------------------------------------------------------------
Exp_function::~Exp_function() {
  for (std::list<Expression*>::const_iterator it = args_.begin();
  it != args_.end(); it++) {
    delete *it;
  }
}
//------------------------------------------------------------------
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
//-----------------------------------------------------------------
St_list::~St_list() {
  for(std::list<Statement*>::const_iterator it = statement_.begin();
  it != statement_.end(); it++) {
    delete *it;
  }
}
//------------------------------------------------------------------
void St_list::print(std::ostream& os, int indent) const {
  for(std::list<Statement*>::const_iterator it = statement_.begin();
  it != statement_.end(); it++) {
    (*it)->print(os, indent);
  }
}
