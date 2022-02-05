#include <iostream>
#include <stdexcept>

class Vector {
private:
  int* vec;
  std::size_t size;
public:
  Vector() {
  vec = nullptr;
  size = 0;
  }
  Vector(int n) {
    if (n <= 0) {
      throw std::bad_alloc();
    }
    vec = new int[n];
    size = n;
  }
  int& operator[](size_t i) {
    if (i > size) {
      throw std::out_of_range("添字が範囲外です。");
    }
    return vec[i];
  }
  Vector operator+(const Vector& v) {
    if(size != v.size) {
      throw std::invalid_argument("ベクトルの次元が異なっています。");
    }
    Vector tmp(size);
    for (size_t i = 0; i < size; i++) {
      tmp.vec[i] = vec[i] + v.vec[i];
    }
    return tmp;
  }
  Vector& operator=(const Vector& v) {
    if(this != &v) {
      delete[] vec;
      size = v.size;
      vec = new int[v.size];
      for (size_t i = 0; i < v.size; i++) {
        vec[i] = v.vec[i];
      }
    }
    return *this;
  }
};

int main() {
  try {
    Vector a;
    Vector b(4);
    Vector c(3);
    for (int i = 0; i < 4; i++) {
      b[i] = i;
      c[i] = i;
    }
    a = b + c;
  }
  catch(const std::bad_alloc& e) {
    std::cout << "次元が正しくありません。" << std::endl;
  }
  catch(const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}