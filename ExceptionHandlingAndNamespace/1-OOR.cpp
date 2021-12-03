#include <iostream>
#include <stdexcept>
using namespace std;

int main(void) {
  int month, day;
  cout << "今月は何月? ";
  cin >> month;
  cout << "今日は何日? ";
  cin >> day;
  try {
    if (month < 1 || month > 12 || day < 1 || day > 31) {
      throw out_of_range("out of range");
    }
    cout << "今日は" << month << "月" << day << "日です。" << endl;
  }
  catch (const exception& e) {
    cout << e.what() << endl;
    return -1;
  }
}
