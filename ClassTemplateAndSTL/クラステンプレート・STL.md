# クラステンプレート・STL 

<div style="text-align: right"><strong>2I06 糸川倫太朗</strong></div>

### 1

> Pointクラスをテンプレート化せよ。（クラス宣言内でのメンバ関数の定義）

```cpp
#include <iostream>
using namespace std;

template<class T>
class Point {
    T x;
    T y;
  public:
    Point() {
      x = 0;
      y = 0;
    }
    Point(T x, T y) {
      set(x, y);
    }
    void set(T x, T y) {
      this -> x = x;
      this -> y = y;
    }
    T getx() {
      return x;
    }
    T gety() {
      return y;
    }
};

int main() {
  Point<int> p1(1, 2);
  Point<double> p2;
  cout << p1.getx() << "," << p1.gety() << endl;
}
```

### 2

> １．のプログラムにおいて、Pointクラスの宣言を次のように記述したとき、Pointクラスをテンプレート化せよ。（クラス宣言外でのメンバ関数の定義）

```cpp
#include <iostream>
using namespace std;

template<class T>
class Point {
    T x;
    T y;
  public:
    Point();
    Point(T x, T y);
    void set(T x, T y);
    T getx();
    T gety();
};

template<class T>
Point<T>::Point() {
  x = 0;
  y = 0;
}

template<class T>
Point<T>::Point(T x, T y) {
  set(x, y);
}

template<class T>
void Point<T>::set(T x, T y) {
  this -> x = x;
  this -> y = y;
}

template<class T>
T Point<T>::getx() {
  return x;
}

template<class T>
T Point<T>::gety() {
  return y;
}

int main() {
  Point<int> p1(1, 2);
  Point<double> p2;
  cout << p1.getx() << "," << p1.gety() << endl;
}
```

### 3

> 次の（ア）～（カ）の処理をするプログラムを完成させよ。ただし各行の行末の命令を使うこと。
>
> (ア)unsigned char型を扱うvectorオブジェクトstrを作成 
>
> (イ)strの要素に’p’, 'r’, 'o’, 'g’, 'r’, 'a’, 'm’を入れる。(push_back) 
>
> (ウ)strの各要素を表示(size) 
>
> (エ)str中の’r’の最初の位置を表示(find) 
>
> (オ)str中の各要素をアルファベット順に並び替え(sort)
>
> (カ)strの各要素を表示(イテレータ) 

```cpp
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
```

