/**
 * https://leetcode.com/problems/possible-bipartition/description/
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>

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
        bool dfs(int cur, int color) {
            _colors[cur] = color;
            for (int n : _g[cur]) {
                if (_colors[n] == color) return false;
                if (_colors[n] == 0 && !dfs(n, -color)) return false;
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
