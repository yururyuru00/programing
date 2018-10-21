#include <iostream>
#include <assert.h>

class stack {
  private:
    int sp;
    int max;
    int* data;
  public:
    stack(int sz) {sp=0; max=sz; data=new int[max];}
    ~stack() {delete [] data;}
    void push(int d) {assert(sp<=max); data[sp++]=d;}
    void pop() {assert(0<sp); --sp;}
    bool empty() const {return sp==0;}
    int top() const {return data[sp-1];}
    int size() const {return sp;}
    void dump(std::ostream&) const;
};

void stack::dump(std::ostream& os) const {
  os << "max=" << max << ", ";
  os << "sp=" << sp << ", ";
  os << "data=(";
  for (int i=0; i<sp; i++) os << data[i] << " ";
  os << ")" << std::endl;
}


int main() {
  stack s1(5), s2(7);

  s1.push(1); s1.push(3); s1.push(5);

  s2 = s1;

  s1.pop(); s1.pop(); s1.push(300); s1.push(500);

  s1.dump(std::cout);
  s2.dump(std::cout);
  return 0;
}
