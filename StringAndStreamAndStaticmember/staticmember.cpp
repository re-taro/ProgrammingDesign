#include<iostream>
#include<string>
using namespace std;

class Pet {
  private:
    string name;
    static unsigned int total;
  public:
    Pet(const string& n) {
      name = n;
      total++;
    }
    void Name(void) {
      cout << name << endl;
    }
    static unsigned int totalPets(void) {
      return total;
    }
    ~Pet(void) {
      total--;
    }
};

int main(void) {
  string taro = "taro";
  string jiro = "jiro";
  Pet* p1 = new Pet(taro);
  Pet* p2 = new Pet(jiro);
  p1->Name();
  p2->Name();
  cout << Pet::totalPets() << endl;
  delete p1;
  cout << Pet::totalPets() << endl;
}
