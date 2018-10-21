#include <iostream>
#include "ast.h"

int main()
{
Statement* s = make_if();
s->print(std::cout, 1);
return 0;
}
