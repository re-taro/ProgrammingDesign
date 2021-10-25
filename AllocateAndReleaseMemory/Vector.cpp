#include <cstddef>

class Vector {
  private:
    double* vec;
    size_t _size;
  public:
    Vector() {
      vec = nullptr;
      _size = 0;
    }
    Vector(size_t s) {
      _size = s;
      vec = new double[s];
    }
    Vector(const Vector& v) {
      _size = v._size;
      vec = new double[_size];
      for(size_t i = 0; i < _size; i++)
        vec[i] = v.vec[i];
    }
    size_t size() {
      return _size;
    }
    double& operator[](size_t s) {
      return vec[s];
    }
    Vector& operator=(const Vector& v) {
      if(this != &v) {
        delete[] vec;
        _size = v._size;
        vec = new double[_size];
        for(size_t i = 0; i < _size; i++)
          vec[i] = v.vec[i];
      }
      return *this;
    }
    ~Vector() {
      delete[] vec;
    }
};

int main() {
  Vector vec1(10);
  for(size_t i = 0; i < vec1.size(); i++)
    vec1[i] = i;
  Vector vec2 = vec1;
  Vector vec3;
  vec3 = vec1;
}