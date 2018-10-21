#include<iostream>

class Complex {
  private:
    double real; // 実部
    double imag; // 虚部
  public:
    Complex() {real = 0.0; imag = 0.0;}
    Complex(double r, double i) {real = r; imag = i;}
    ~Complex() {}
    double re() const {return real;} // 実部を取り出す
    double im() const {return imag;} // 虚部を取り出す
    void set_re(double r) {real = r;} // 実部を設定
    void set_im(double i) {imag = i;} // 虚部を設定
    void print(std::ostream& os) const { // 出力
      os << real << "+" << imag << "i" << std::endl;
    }
    Complex& operator+=(const Complex&);
  };

  Complex& Complex::operator+=(const Complex& c) {
    real += c.real;
    imag += c.imag;
    return *this;
  }

  int main(void) {
    Complex c1 = Complex(1.2, 1.5);
    Complex c2 = Complex(1.7, 3.1);
    c1.print(std::cout);
    c1 += c2;
    c1.print(std::cout);
  }
