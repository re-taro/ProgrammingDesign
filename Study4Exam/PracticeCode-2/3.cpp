#include <iostream>
using namespace std;

class Point {
private:
  int x, y, z;
public:
  friend istream& operator>>(istream& in, Point& p);
  friend ostream& operator<<(ostream& out, const Point& p);
};

istream& operator>>(istream& in, Point& p) {
  in >> p.x >> p.y >> p.z;
  return in;
}

ostream& operator<<(ostream& out, const Point& p) {
  out << p.x << ' ' <<p.y << ' ' << p.z;
  return out;
}

int main(void) {
  Point p;
  cout << "入力:";
  cin >> p;
  cout << "出力:" << p << endl;
}