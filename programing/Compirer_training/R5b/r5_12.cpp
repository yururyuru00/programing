#include <iostream>
#include "ast.h"

int main()
{
  Variable* v = new Variable(Type_INT, "a");
  v->print(std::cout);
  return 0;
}
