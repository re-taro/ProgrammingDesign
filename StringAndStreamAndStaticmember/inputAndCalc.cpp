#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
  ifstream file;
  file.open("data.txt");
  double result = 0.;
  string value;
  double num = 0.;
  while (true) {
    file >> value;
    if (!file.eof()) {
      num = stod(value);
      result += num;
      continue;
    }
    break;
  }
  cout << result << endl;
}
