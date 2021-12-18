#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
  ofstream file;
  file.open("output.txt");
  string sentence = "Department of Electronic and Information Engineering";
  stringstream tmp;
  tmp << sentence;
  while (true) {
    if (!tmp.eof()) {
      string element;
      tmp >> element;
      file << element << endl;
      continue;
    }
    break;
  }
}