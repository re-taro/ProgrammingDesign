#include <iostream>
using namespace std;
class Minute {
  private:
    int minute;
  public:
    Minute() {minute = 0;}
    Minute(int i) {
      minute = i;
    }
    Minute& operator=(int i) {
      minute = i;
      return *this;
    }
    Minute operator+(const Minute& m) {
      return Minute(minute + m.minute);
    }
    friend Minute operator+(const int& i, const Minute& m);
    Minute operator++(int dummy) {
      minute++;
      return *this;
    }
    operator int() {
      return minute;
    }
};

Minute operator+(const int& i, const Minute& m) {
  return Minute(i + m.minute);
}

int main() {
  Minute a;
  Minute b = 3; // (A)
  Minute c;
  int d;
  a = 20;       // (B)
  c = a + b;    // (C)
  b = 10 + c;   // (D)
  b++;          // (E)
  d = b;        // (F)
}