#include<iostream>
using namespace std;

class Animal {
  public:
    virtual void say() = 0;
};

class Human : public Animal {
  public:
    void say() {}
    void speak() {
      cout << "speak" << endl;
    }
};

class Dog : public Animal {
  public:
    void say() {}
    void bark() {
      cout << "bark" << endl;
    }
};

void say(Animal* a) {
  Human* h = dynamic_cast<Human*>(a);
  Dog* d = dynamic_cast<Dog*>(a);

  if(h) {
    h -> speak();
  }
  if(d) {
    d -> bark();
  }
}

int main() {
  Human human;
  Dog dog;
  say(&human);
  say(&dog);
}