#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

class Score {
  private:
    vector<int> subscore;
  public:
    void set(const vector<int>& s) {
      subscore = s;
    }
    vector<int>& get() {
      return subscore;
    }
    int total() const {
      int result = 0;
      for (auto it = subscore.begin(); it != subscore.end(); it++) {
        result += *it;
      }
      return  result;
    }
    bool operator<(const Score& s) const {
      int result = 0;
      for(auto it = subscore.begin(); it != subscore.end(); it++) {
        result += *it;
      }
      if(result < s.total()) {
        return true;
      }
      return false;
    }
    void show() {
      int result = 0;
      for(auto it = subscore.begin(); it != subscore.end(); it++) {
        result += *it;
        cout << *it << " ";
      }
      cout << ": " << result << endl;
    }
};

int main() {
  random_device rnd;
  mt19937_64 mt(rnd());
  uniform_real_distribution<> sr(0, 10);
  int nplayer;
  int nsubscore;
  cout << "選手の人数：";
  cin >> nplayer;
  cout << "評価項目の数：";
  cin >> nsubscore;
  vector<Score> players;
  for(int i = 0; i < nplayer; i++) {
    Score player;
    vector<int> s;
    for(int j = 0; j < nsubscore; j++) {
      s.push_back(sr(mt));
    }
    player.set(s);
    players.push_back(player);
  }
  cout << "------------" << endl;
  sort(players.begin(), players.end());
  for(int i = 0; i < players.size(); i++) {
    players[i].show();
  }
}