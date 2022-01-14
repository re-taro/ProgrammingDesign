#include <iostream>
#include <fstream>
using namespace std;

class fs_error: public logic_error {
  public:
    fs_error(const string& what_arg): logic_error(what_arg) {}
};

int main(int argc, char* argv[]) {
  try {
    if (argc != 3) {
      throw out_of_range("out of range");
    }
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    string tmp;
    if (in.fail() || out.fail()) {
      throw fs_error("file couldn't open");
    }
    while (!in.eof()) {
      getline(in, tmp);
      out << tmp << endl;
    }
    in.close();
    out.close();
    return 0;
  }
  catch (exception& e) {
    cout << e.what() << endl;
    return -1;
  }
}
