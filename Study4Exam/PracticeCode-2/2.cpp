#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char* argv[]) {
  for (int i = 1; i < argc; i++) {
    string str(argv[i]);
    reverse(str.begin(), str.end());
    cout << str << endl;
  }
}