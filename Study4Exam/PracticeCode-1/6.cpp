#include <iostream>
using namespace std;

template <class T>
class Vector {
  private:
    T *vec;
    size_t size;
  public:
    size_t getSize() {return size;}
    Vector() { // (A) 要素数0
      vec = nullptr;
      size = 0;
    }
    Vector(size_t n) {// (B) n次元のベクトルを作成（要素数n）
      vec = new T[n];
      size = n;
    }
    T& operator[](size_t s);
    Vector (const Vector& v) {
      size = v.size;
      vec = new T[v.size];
      for(size_t s = 0; s < v.size; s++) {
        vec[s] = v.vec[s];
      }
    }
    Vector& operator=(const Vector& v) {
      if(this != &v) {
        delete[] vec;
        size = v.size;
        vec = new T[v.size];
        for(size_t s = 0; s < v.size; s++) {
          vec[s] = v.vec[s];
        }
      }
      return *this;
    }
    ~Vector() {
      delete[] vec;
    }
};

template <class T>
T& Vector<T>::operator[](size_t s) {
  return vec[s];
}

int main() {
  Vector<double> v1(10);
  for (size_t i = 0; i < v1.getSize(); i++)
    v1[i] = i; // (C)
  Vector<double> v2 = v1; // (D)
  Vector<double> v3;
  v3 = v1;  // (E)
}  // (F) デストラクタ