#include <iostream>
using namespace std;

class Occupation {
  public:
    int exp;
    Occupation() : exp(0) {}
};

class Fighter : public Occupation {
  public:
    void slash() {
      cout << "slash" << endl;
    }
};

class Mage : public Occupation {
  public:
    void castSpell() {
      cout << "attack spell" << endl;
    }
};

class Priest : public Occupation {
  public:
    void castSpell() {
      cout << "cure spell" << endl;
    }
};

class Thief : public Occupation {
  public:
    void release() {
      cout << "release" << endl;
    }
};

class Bishop : public Mage, public Priest {};

class Ninja : public Fighter, public Thief {};

int main() {
  Fighter taro;
  Bishop hanako;
  Ninja jiro;

  cout << "Their's status" << endl;
  cout << "=====================" << endl;
  cout << "Name" << '\t' << "Job" << '\t' << "Exp" << endl;
  cout << "Taro" << '\t' << "Fighter" << '\t' << taro.exp << endl;
  cout << "Hanako" << '\t' << "Bishop" << '\t' << hanako.Mage::exp + hanako.Priest::exp << endl;
  cout << "Jiro" << '\t' << "Ninja" << '\t' << jiro.Fighter::exp + jiro.Thief::exp << endl;
  cout << "=====================" << endl;
  cout << endl;

  cout << "Taro:" << '\t';
  taro.slash();
  taro.exp += 10;

  cout << "Hanako:" << '\t';
  hanako.Priest::castSpell();
  hanako.Priest::exp += 10;

  cout <<  "Jiro:" << '\t';
  jiro.release();
  jiro.Thief::exp += 10;

  cout << endl;

  cout << "Their's status" << endl;
  cout << "=====================" << endl;
  cout << "Name" << '\t' << "Job" << '\t' << "Exp" << endl;
  cout << "Taro" << '\t' << "Fighter" << '\t' << taro.exp << endl;
  cout << "Hanako" << '\t' << "Bishop" << '\t' << hanako.Mage::exp + hanako.Priest::exp << endl;
  cout << "Jiro" << '\t' << "Ninja" << '\t' << jiro.Fighter::exp + jiro.Thief::exp << endl;
  cout << "=====================" << endl;
}