#include <iostream>
#include "ast.h"

int main()
{
  Function* f = make_function_asum();
  f->print(std::cout);

  return 0;
}
