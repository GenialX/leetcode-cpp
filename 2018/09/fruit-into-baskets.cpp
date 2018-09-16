/**
 * https://leetcode.com/problems/sum-of-subarray-minimums/
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Solution {
    public:
        int totalFruit(vector<int>& tree) {
            map<int, int> m;
            map<int, int>::iterator it;
            int l = 0, r = 0, len = tree.size(), a = 0;
            while (r < len) {
                if (m.size() <= 2) {
                    it = m.find(tree[r]);
                    if (it != m.end()) {
                        it->second++;
                        m.insert(make_pair(tree[r], it->second + 1));
                    } else {
                        m.insert(make_pair(tree[r], 1));
                    }
                    r++;
                    if (a < r - l) a = r - l;
                } else {
                    it = m.find(tree[l]);
                    m.erase(tree[l]);
                    if (it->second != 1) {
                        m.erase(tree[l]);
                        m.insert(make_pair(tree[l], it->second - 1));
                        it = m.find(tree[l]);
                    }
                    l++; 
                }
            }
            return a;
        }
};

int main(int argc, char * argv[]) {
    int c = 0;
    Solution * s = new Solution();
    vector<int> l1;
    l1.push_back(1);
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(2);
    l1.push_back(2);
    c = s->totalFruit(l1);
    cout<<c<<endl;
}
