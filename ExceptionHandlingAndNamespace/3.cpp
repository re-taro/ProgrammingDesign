#include <iostream>
using namespace std;
namespace exam {
  namespace japanese {
    void question(void) {
      cout << "あなたは日本語が好きですか?" << endl;
    }
    int score;
  }
  namespace english {
    void question(void) {
      cout << "Do you like English?" << endl;
    }
    int score;
  }
}

int main(void) {
  exam::japanese::score = 90;
  exam::english::score = 10;
  exam::japanese::question();
  {
    using namespace exam;
    cout << japanese::score << endl;
  }
  {
    using namespace exam::english;
    question();
    cout << score << endl;
  }
}
