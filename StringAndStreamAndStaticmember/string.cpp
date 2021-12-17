#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
  string str1;
  string str2 = "Program Design";
  string str3;
  cin >> str1;
  reverse(str2.begin(), str2.end());
  str3 = str1 + str2;
  cout << str3 << endl;
}
