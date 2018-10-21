#include <iostream>

class Complex {
  private:
    double real;
    double imag;
  public:
    Complex() {
      real = 0.0; imag = 0.0;
      std::cout << "Complex()" << std::endl;
    }
    Complex(double r, double i) {
      real = r; imag = i;
      std::cout << "Complex(" << r << "," << i << ")" << std::endl;
    }
    Complex(const Complex& c) {
      real = c.real; imag = c.imag;
      std::cout << "Complex(const Complex&)" << std::endl;
    }
   ~Complex() {std::cout << "~Complex()" << std::endl;}
    Complex& operator=(const Complex& c) {
      real = c.real; imag = c.imag;
      std::cout << "operator=(const Complex& c)" << std::endl;
      return *this;
  }
    double re() const {return real;}
    double im() const {return imag;}
    void set_re(double r) {real = r;}
    void set_im(double i) {imag = i;}
    void print(std::ostream& os) const {os << real << "+" << imag << "i";}
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  c.print(os);
  return os;
}

Complex operator+(Complex a, Complex b) {
  Complex c;
  c.set_re(a.re() + b.re());
  c.set_im(a.im() + b.im());
  return c;
}

int main(void) {
  Complex x(3.14,2.26);
  Complex y = x;
  Complex z;
  
  z = x + y; // z = operator+(x,y)
  std::cout << z << std::endl;
  return 0;
}
