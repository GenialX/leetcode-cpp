#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<char, int> orderm;
    string order = "";
    bool cmp(const string& s1, const string& s2) {
        int l1 = s1.size(), l2 = s2.size(), i = 0;
        while (i < l1 && i < l2) {
            if (s1[i] == s2[i]) {
                ++i;
            } else {
                return orderm[s1[i]] <= orderm[s2[i]];
            }
        }
        return l1 <= l2;
    }
public:
    bool isAlienSorted(vector<string>& words, string _order) {
        order = _order;
        for (int i = 0; i < order.size(); ++i) {
            orderm[i] = order[i];
        }
        for (int i = 0; i < words.size() - 1; ++i) {
            if (cmp(words[i], words[i + 1])) {
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
};


int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    vector<string> words{"word","word","row"};
    string order = "worldabcefghijkmnpqstuvxyz";
    bool res = s->isAlienSorted(words, order);
    if (res) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}
