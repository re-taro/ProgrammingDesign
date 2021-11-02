#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void print(const vector<unsigned char>& vec) {
  for(int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}

int main() {
  vector<unsigned char> str;
  const char element[] = " program";
  for (int i = 0; i < 8; i++) {
    str.push_back(element[i]);
  }
  for (int i = 0; i < str.size(); i++) {
    cout << str[i] << " ";
  }
  cout << endl;
  vector<unsigned char>::iterator result = find(str.begin(), str.end(), 'r');
  if(result == str.end()) {
    cout << "404 Not Found" << endl;
  }
  else {
    cout << "position: " << distance(str.begin(), result) << endl;
  }
  sort(str.begin(), str.end());
  print(str);
  for(vector<unsigned char>::iterator it = str.begin(); it != str.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}