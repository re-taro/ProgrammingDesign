#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

int CountNumOfTextLines(const char* path) {
  int i = 0;
  ifstream file(path);
  if(file) {
    string line;
    while(true) {
      getline( file, line );
      i++;
      if(file.eof())
        break;
      }
    }
	return i;
}

int main(void) {
  ifstream file;
  file.open("time.txt");
  cout.setf(ios::right, ios::adjustfield);
  cout << "------------" << endl;
  cout << '|' << setw(2) << 'n' << '|' << setw(7) << 's' << '|' << endl;
  for (int i = 0; i < CountNumOfTextLines("time.txt"); i++) {
    string buf;
    getline(file, buf);
    stringstream tmp;
    tmp << buf;
    tmp >> buf;
    cout << '|' << setw(2) << buf;
    tmp >> buf;
    cout << '|' << setw(7) << buf << '|' << endl;
  }
  cout << "------------" << endl;
}
