#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

class Members {
private:
  wstring addr;
  int number;
public:
  void addPref(const wstring& pref) {
    addr = pref + addr;
  }
  int getNumber(void) {
    return number;
  }
  friend wistream& operator>>(wistream& in, Members& m) {
    in >> m.addr >> m.number;
    return in;
  }
  friend wostream& operator<<(wostream& out, const Members& m) {
    out << setfill(L'　') << left << setw(10) << m.addr << setw(8) << m.number << endl;
    return out;
  }
};

int main(void) {
  locale::global(locale("ja_JP.UTF-8"));
  vector<Members> members;
  wifstream in("data1.txt");
  wofstream out("data2.txt");
  wstring pref;
  int total = 0;
  in >> pref;
  while(true) {
    Members m;
    in >> m;
    if (in.eof())
      break;
    m.addPref(pref);
    total += m.getNumber();
    members.push_back(m);
  }
  for (auto& m : members)
    out << m;
  out << setfill(L'　') << left << setw(10) << L"合計" << setw(8) << total << endl;
}