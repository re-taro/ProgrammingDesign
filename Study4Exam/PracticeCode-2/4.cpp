#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
  int n;
  float w;
  float total = 0.0f;
  ifstream in;
  in.open("data.txt");
  while(!in.eof()) {
    in >> n >> w;
    total += static_cast<float>(n*w);
  }
  ofstream out;
  out.open("output.txt");
  out << total;
}