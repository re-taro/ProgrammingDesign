#include <iostream>
using namespace std;

class Point {
  private:
    double x, y, z;
  public:
    Point(void) : x(0), y(0), z(0) {}
    friend istream& operator>>(istream& in, Point& p) {
      in >> p.x >> p.y >> p.z;
      return in;
    }
    friend ostream& operator<<(ostream& out, const Point& p) {
      out << p.x << ' ' << p.y << ' ' << p.z;
      return out;
    }
};

int main(void) {
  Point p;
  cout << "入力: ";
  cin >> p;
  cout << "出力: " << p << endl;
}
