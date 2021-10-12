#include <iostream>
using namespace std;

class Vector2 {
  private:
    int x;
    int y;
  public:
    Vector2(int x = 0, int y = 0) {
      this -> x = x;
      this -> y = y;
    }
    void show() {
      cout << "(" << x << ", " << y << ")" << endl;
    }
    Vector2 operator+() {
      return *this;
    }
    Vector2 operator+(Vector2 v) {
      return Vector2(this -> x + v.x, this -> y + v.y);
    }
    Vector2 operator++() {
      return Vector2(++x, ++y);
    }
    Vector2 operator++(int d) {
      return Vector2(x++, y++);
    }
    Vector2 operator-() {
      return Vector2(-x, -y);
    }
    int operator*(Vector2 v) {
      return int(this -> x * v.x + this -> y * v.y);
    }
    Vector2 operator*(int n) {
      return Vector2(this -> x * n, this -> y * n);
    }
    friend Vector2 operator*(int n, Vector2 v);
};

Vector2 operator*(int n, Vector2 v) {
  return Vector2(n * v.x, n * v.y);
}

int main() {
  Vector2 v1(1, 3);
  Vector2 v2(5,2);
  Vector2 v;

  ++v1;
  v = 2 * v1 + (-v1) * (+v2 * v1);
  v++;
  v.show();
}