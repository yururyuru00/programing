#include <iostream>

class aaa {
public:
  int x;
  int y;
  aaa() {std::cout << "aaa()" << std::endl;}
  aaa(int xx, int yy) {
    x=xx; y=yy;
    std::cout << "aaa(" << xx << "," << yy << ")" << std::endl;
  }
  ~aaa() {std::cout << "∼aaa()" << std::endl;}
};
class bbb {
public:
  int x;
  int y;
  bbb() {std::cout << "bbb()" << std::endl;}
  ~bbb() {std::cout << "∼bbb()" << std::endl;}
};
class ccc {
public:
  aaa p;
  bbb q;
  ccc() {std::cout << "ccc()" << std::endl;}
  ~ccc() {std::cout << "∼ccc()" << std::endl;}
};

int main(void) {
  aaa a;
  bbb x[3];
  aaa *p;
  p = new aaa;
  a = aaa(3,4);
  std::cout << a.x << std::endl;
  for (int i=0; i<3; i++) {
    aaa x(7,4);
  }
  delete p;
  ccc c;
  return 0;
}
