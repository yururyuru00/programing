#include <iostream>
#include <string>

class trace {
  private:
    std::string name;
  public:
    trace(const std::string& nm) { // 文字列引数を持つコンストラクタ
      name = nm; // 受け取った文字列を記憶
      std::cerr << name << " begin" << std::endl; // ○○○ begin と表示
    }
    ~trace() { // デストラクタ
      std::cerr << name << " end" << std::endl; // ○○○ end と表示
    }
  };

int add(int a, int b) {
  trace t("add");
  return a+b;
  }

  int main(void) {
    trace t1("main");
    for (int i=0; i<3; i++) {
      trace t2("for-loop");
      int c = add(i,i*i);
    }
    return 0;
  }
