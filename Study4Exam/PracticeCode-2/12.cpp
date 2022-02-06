#include <iostream>
using namespace std;
namespace paper {
  namespace A4 {
    void size() {cout << "A4" << endl;}
  }
  namespace A5 {
    void size() { cout << "A5" << endl;}
  }
}
int main() {
  using namespace paper;
  A4::size();
  {
    using namespace A5;
    size();
  }
}