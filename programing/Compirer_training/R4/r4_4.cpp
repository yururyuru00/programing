#include <iostream>
#include <assert.h>

class stack {
protected:
    int sp;
    int max;
    int* data;
  public:
    stack() {stack(10);}
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

class stack_ac :public stack {
  private:
    int push_counter;
    int pop_counter;
  public:
    stack_ac() {
      push_counter=0;
      pop_counter=0;
    }
    stack_ac(int sz):
      stack(sz)
      {
      push_counter=0;
      pop_counter=0;
    }
    void push(int d) {
      stack::push(d);
      push_counter++;
    }
    void pop() {
      stack::pop();
      pop_counter++;
    }
    int n_push() {return push_counter;}
    int n_pop() {return pop_counter;}
};

int main(void) {
  stack_ac s1 = stack_ac(10);
  stack_ac s2 = stack_ac(10);

  s1.push(4); s1.push(3); s1.push(65);
  s1.push(2); s1.pop(); s1.pop();

  s2.push(2); s2.push(1); s2.pop();
  s2.push(11);  s2.pop(); s2.pop();

  s1.dump(std::cout);
  std::cout << "push_coounter :" << s1.n_push() << std::endl;
  std::cout << "pop_coounter :" << s1.n_pop() << std::endl;

  std::cout << std::endl;

  s2.dump(std::cout);
  std::cout << "push_coounter :" << s2.n_push() << std::endl;
  std::cout << "pop_coounter :" << s2.n_pop() << std::endl;

}
