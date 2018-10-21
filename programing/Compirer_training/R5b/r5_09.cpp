#include <iostream>
#include "ast.h"

int main()
{
  Statement* s = make_while();
  s->print(std::cout, 0);

  return 0;
}
