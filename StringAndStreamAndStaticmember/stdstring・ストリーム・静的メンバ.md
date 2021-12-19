# std::string・ストリーム・静的メンバ 

<div style="text-align: right"><strong>2I06 糸川倫太朗</strong></div>

### 1

> シングルバイト文字・ワイド文字・マルチバイト文字について調査し，説明せよ．

- 1byteで表現する文字をシングルバイト文字、複数byteで表現するものマルチバイト文字という。ASCIIはシングルバイト文字、Shift-JISとEUCとUnicodeはマルチバイト文字となる。ワイド文字は固定長の文字を扱う型で、環境により2byteと4byteの場合がある。
    大抵の場合、これらの型にはUTF-16かUTF-32を当てはめて使用する。

### 2

>  std::stringを用いた次のプログラムを完成させよ．

```cpp : string.cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
  string str1;
  string str2 = "Program Design";
  string str3;
  cin >> str1;
  reverse(str2.begin(), str2.end());
  str3 = str1 + str2;
  cout << str3 << endl;
}

```

### 3

> 標準入力から数値(double型)を入力が終わるまで受け取り，ファイルに保存するプログラムを作成せよ．なお，ファイル名は”data.txt”で，1行に一つの数値が書かれている．

```cpp : output2data.cpp
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(void) {
  ofstream file;
  file.open("data.txt");
  double data;
  string value;
  while (true) {
    getline(cin, value);
    if (value.length()) {
      data = stod(value);
      file << data << endl;
      continue;
    }
    break;
  }
  file.close();
}

```

### 4

> 問3で作成したファイル"data.txt"を読み込み，合計を表示するプログラムを作成せよ．

```cpp : inputAndCalc.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
  ifstream file;
  file.open("data.txt");
  double result = 0.;
  string value;
  double num = 0.;
  while (true) {
    file >> value;
    if (!file.eof()) {
      num = stod(value);
      result += num;
      continue;
    }
    break;
  }
  cout << result << endl;
}

```

### 5

> stringstreamを用いて，文字列"Department of Electronic and Information Engineering"を単語に分割し，ファイル"output.txt"にその単語を1行に1単語ずつ保存せよ．

```cpp : wakati.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
  ofstream file;
  file.open("output.txt");
  string sentence = "Department of Electronic and Information Engineering";
  stringstream tmp;
  tmp << sentence;
  while (!tmp.eof()) {
    string element;
    tmp >> element;
    file << element << endl;
  }
}

```

### 6

> 次のプログラムを完成せよ．ただし，main関数内を変更してはいけない．

```cpp : customstream.cpp
#include <iostream>
using namespace std;

class Point {
  private:
    double x, y, z;
  public:
    Point(void) : x(0), y(0), z(0) {}
    friend istream& operator>>(istream& in, Point& p) {
      in >> p.x >> p.y >> p.z;
      return in;
    }
    friend ostream& operator<<(ostream& out, const Point& p) {
      out << p.x << ' ' << p.y << ' ' << p.z;
      return out;
    }
};

int main(void) {
  Point p;
  cout << "入力: ";
  cin >> p;
  cout << "出力: " << p << endl;
}

```

### 7

> 体内時計の正確さを調べるために，100分の1秒まで計測できるストップウオッチを用いて，目を閉じて10秒計測してみた．その結果を以下のファイルに保存した．1行が一回の試行で，1列目が(回)，2列目が計測結果(秒)である.このファイルを読み込み，マニピュレータを用いて以下のように表示せよ．（幅は指定通り，データは右づめ．使用するマニピュレータについては，調査すること） 

```cpp : output2manipulator.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

int CountNumOfTextLines(const char* path) {
  int i = 0;
  ifstream file(path);
  if(file) {
    string line;
    while(true) {
      getline( file, line );
      i++;
      if(file.eof())
        break;
      }
    }
	return i;
}

int main(void) {
  ifstream file;
  file.open("time.txt");
  cout.setf(ios::right, ios::adjustfield);
  cout << "------------" << endl;
  cout << '|' << setw(2) << 'n' << '|' << setw(7) << 's' << '|' << endl;
  for (int i = 0; i < CountNumOfTextLines("time.txt"); i++) {
    string buf;
    getline(file, buf);
    stringstream tmp;
    tmp << buf;
    tmp >> buf;
    cout << '|' << setw(2) << buf;
    tmp >> buf;
    cout << '|' << setw(7) << buf << '|' << endl;
  }
  cout << "------------" << endl;
}

```

### 8

> 次のプログラムについて答えよ．

#### (ア)

> ペットの数の合計を記録するための静的メンバ変数を追加するためにどうすればよいか．

- Petクラスのメンバ変数に`static unsigned int total;`を追加する

#### (イ)

> ペットの数の合計を返却するための静的メンバ関数を追加するためにどうすればよいか．

- Petクラスのメンバ関数に

    ```cpp
    	static unsigned int totalPets(void) {
          return total;
        }
    ```

    を追加する

#### (ウ)

> オブジェクトの増減に対応して，プログラム中のペットの数を正しく数えるための仕組みを追加するためにどうすればよいか．

- コンストラクタで静的メンバをインクリメント、デストラクタで静的メンバをデクリメントする。
