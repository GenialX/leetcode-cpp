/**
 * https://leetcode.com/problems/possible-bipartition/description/
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <stack>

using namespace std;

class Solution {
    public:
        bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
            // create the graph(two-demontional array)
            _g = vector< vector<int> >(N);
            for (int i = 0; i < N; ++i) {
                _g[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
                _g[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
            }

            _colors = vector<int>(N, 0); // 0 unkone, 1 red, -1 blue
            for (int i = 0; i < N; ++i) {
                if (_colors[i] == 0 && !dfs(i, 1)) return false;
            }
            return true;
        }

    private:
        vector< vector<int> > _g;
        vector<int> _colors;
        vector<int> _sstack;
        bool dfs(int cur, int color) {
            stack< vector<int> > _stack;
            _stack.push(vector<int> {cur, color});

            while (_stack.size()) {
                _sstack = _stack.top();
                _stack.pop();

                _colors[_sstack[0]] = _sstack[1];
                for (int n : _g[_sstack[0]]) {
                    if (_colors[n] == _sstack[1]) return false;
                    if (_colors[n] == 0) _stack.push(vector<int> {n, -_sstack[1]});
                }
            }

            return true;
        }
};

int main(int argc, char * argv[]) {
    bool c;
    Solution * s = new Solution();
    //[[1,2],[1,3],[2,3]]
    vector< vector<int> > l;
    vector<int> l1, l2, l3;
    l1.push_back(1);
    l1.push_back(2);
    l2.push_back(1);
    l2.push_back(3);
    l3.push_back(2);
    l3.push_back(3);
    l.push_back(l1);
    l.push_back(l2);
    l.push_back(l3);
    c = s->possibleBipartition(3, l);
    cout<<c<<endl;
}
