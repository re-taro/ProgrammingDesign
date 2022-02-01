#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

int main(int argc, char* argv[]) {
  try {
    if (argc != 3) {
      throw out_of_range("out of range");
    }
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    if (in.fail() | out.fail()) {
      throw logic_error("file couldn't open");
    }
    out << in.rdbuf();
    in.close();
    out.close();
    return 0;
  }
  catch (exception& e) {
    cout << e.what() << endl;
    return -1;
  }
}
