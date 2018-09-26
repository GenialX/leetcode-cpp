/**
 * https://leetcode.com/contest/weekly-contest-98/problems/find-and-replace-pattern/
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Solution {
  public:
      vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
          int push = 0;
          vector<string> a;
          map<char, vector<int>> om, tm;
          map<char, vector<int>>::iterator it;
          for (string word : words) {
              if (word.size() != pattern.size()) continue;
              push = 0;
              for (int i = 0; i < (int)word.size(); i++) {
                 //cout<<"w:"<<word.at(i)<<" "<<"p:"<<pattern.at(i)<<endl;
                 if (om.count(word.at(i)) != tm.count(pattern.at(i))) break;
                 if (om.count(word.at(i)) > 0 && sameIndex(om.at(word.at(i)), tm.at(pattern.at(i))) == false) break;
                 //cout<<"w2:"<<word.at(i)<<" "<<"p2 :"<<pattern.at(i)<<endl;
                  // om
                  it = om.find(word.at(i));
                  if (it != om.end()) {
                      vector<int> item = it->second;
                      item.push_back(i);
                      om.erase(word.at(i));
                      om.insert(make_pair(word.at(i), item));
                  } else {
                      om.insert(make_pair(word.at(i), vector<int>{i}));
                  }

                  // tm
                  it = tm.find(pattern.at(i));
                  if (it != tm.end()) {
                      vector<int> item = it->second;
                      item.push_back(i);
                      tm.erase(pattern.at(i));
                      tm.insert(make_pair(pattern.at(i), item));
                  } else {
                      tm.insert(make_pair(pattern.at(i), vector<int>{i}));
                  }
                  if (i == (int)word.size() - 1) push = 1;
              }
              if (push == 1) {
                  //cout<<"push back word:"<<word<<endl;
                  a.push_back(word);
              }
              om.clear();tm.clear();
          }
          return a;
      }

      bool sameIndex(vector<int> a, vector<int> b) {
          for (int i = 0; i < (int)a.size(); i++) {
              if (a[i] != b[i]) return false;
          }
          return true;
      }
};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    vector<string> l1;
    l1.push_back("abb");
    l1.push_back("cde");
    vector<string> l2 = s->findAndReplacePattern(l1, "dee");
}
