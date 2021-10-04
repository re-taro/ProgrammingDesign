#include <iostream>
using namespace std;

class Occupation {
  public:
    int exp;
  private:
    Occupation() {
      exp = 0;
    }
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