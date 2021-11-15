#include <iostream>
using namespace std;

class Complex {
  private:
    double re;
    double im;
  public:
    Complex(double re = 0, double im = 0) {
      this -> re = re;
      this -> im = im;
    }
    Complex operator+(const Complex& c) {
      return Complex(re + c.re, im + c.im);
    }
    Complex operator+(const double& d) {
      return Complex(re + d, im);
    }
    friend Complex operator+(const double& d, const Complex& c);
    Complex operator-(const Complex& c) {
      return Complex(re - c.re, im - c.im);
    }
    Complex operator *(const Complex& c) {
      return Complex((re * c.re) - (im * c.im), (im * c.re) + (re * c.im));
    }
    friend Complex operator*(const double& d, const Complex& c);
    Complex operator/(const Complex& c) {
      double r = re * c.re + im * c.im;
      double i = im * c.re - re * c.im;
      double d = c.re * c.re + c.im * c.im;
      return Complex(r / d, i / d);
    }
    Complex operator/(const double& d) {
      return Complex(re / d, im / d);
    }
    Complex operator++(int dummy) {
      Complex tmp = *this;
      re += 1.0;
      return tmp;
    }
    Complex operator-() {
      return Complex(-re, -im);
    }
    void show() {
      cout << re << " + " << im << "i" << endl;
    }
};

Complex operator+(const double& d, const Complex& c) {
  return Complex(d + c.re, c.im);
}

Complex operator*(const double& d, const Complex& c) {
  return Complex(d * c.re, d * c.im);
}

int main() {
  Complex c1(1.1, 2.2);
  Complex c2(-4.0, 0.5);
  Complex c;

  c = 1.2 + c1 * 3.4 - 0.1  * c1 *  c2  /  c1  +  (-c2  /  5.6  +  7.8);
  c++;
  c.show();
}

/**
 *
 * 表示結果
 * 14.8543 + 7.34071i
 *
 */