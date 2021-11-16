#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
  const char* str = "Pull up if I pul up";
  vector<char> palin;
  for(int i = 0; str[i] != '\0'; i++) {
    palin.push_back(str[i]);
  }
  reverse(palin.begin(), palin.end());
  for(int i = 0; i < palin.size(); i++) {
    cout << palin[i];
  }
  cout << endl;
}