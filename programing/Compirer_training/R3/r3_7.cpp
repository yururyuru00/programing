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
    stack& operator=(const stack& s);
};

void stack::dump(std::ostream& os) const {
  os << "max=" << max << ", ";
  os << "sp=" << sp << ", ";
  os << "data=(";
  for (int i=0; i<sp; i++) os << data[i] << " ";
  os << ")" << std::endl;
}

stack& stack::operator=(const stack& s) {
  if (&s!=this) {
    if (max<s.sp) {
      delete [] data;
      data = new int[max=s.max];
    }
    sp = s.sp;
    for (int i=0; i<sp; i++) data[i] = s.data[i];
  }
  return *this;
}

stack plus(stack s1, stack s2) {
  int sz = s1.size() + s2.size();
  stack tmp(sz), s(sz);
  while(!s2.empty()) {tmp.push(s2.top()); s2.pop();}
  while(!s1.empty()) {tmp.push(s1.top()); s1.pop();}
  while(!tmp.empty()) {s.push(tmp.top()); tmp.pop();}
  return s;
}

  int main(void) {

    stack s1(5);
    stack s2(5);
    stack s(10);

    s1.push(1); s1.push(3); s1.push(5);
    s2.push(2); s2.push(4); s2.push(6);

    s = plus(s1,s2);

    s1.dump(std::cout);
    s2.dump(std::cout);
    s.dump(std::cout);

    return 0;
  }
