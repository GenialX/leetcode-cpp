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
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length();
        unordered_map<string, int> m;
        vector<string> ans{};
        for (int i = 9; i < len; ++i) {
            ++m[s.substr(i - 9, 10)];
        }
        for (auto& p : m) {
            if (p.second > 1) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};

int main(int argc, char * argv[]) {
    Solution *s = new Solution();
    s->findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    return 0;
}
