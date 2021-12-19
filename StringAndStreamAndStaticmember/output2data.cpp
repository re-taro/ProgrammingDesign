#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(void) {
  ofstream file;
  file.open("data.txt");
  double data;
  string value;
  while (true) {
    getline(cin, value);
    if (value.length()) {
      data = stod(value);
      file << data << endl;
      continue;
    }
    break;
  }
  file.close();
}
