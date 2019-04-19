#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>

using namespace std;

class Solution {
    public:
        stack<int> _stack;
        int smallestRangeII(vector<int>& A, int K) {
            if (A.size() == 1) return 0;
            return dfs(0, K, A);
        }

        int dfs(int i, int ck, vector<int>& a) {
            vector<int> B(a.size(), 0);
            stack<vector<int>> _stack;
            _stack.push(vector<int>{i, ck});
            _stack.push(vector<int>{i, -ck});
            int d = 10001;
            vector< vector<int> > dinfo = vector< vector<int> >(a.size());

            while (_stack.size()) {
                // top
                vector<int> item = _stack.top();
                //B[item[0]] = a[item[0]] + item[1];
                if (item[0] == 0) {
                    if (dinfo[0].size()) {
                        dinfo[0].clear();
                    }
                    dinfo[0].push_back(a[item[0]] + item[1]);
                    dinfo[0].push_back(a[item[0]] + item[1]);
                    //cout<<"dinfo[0]:"<<dinfo[0][0]<<" "<<dinfo[0][1]<<"item:"<<item[1]<<endl;
                } else {
                    if (dinfo[item[0]].size()) {
                        dinfo[item[0]].clear();
                    }
                    dinfo[item[0]].push_back(min(dinfo[item[0] - 1][0], a[item[0]] + item[1]));
                    dinfo[item[0]].push_back(max(dinfo[item[0] - 1][1], a[item[0]] + item[1]));
                }
                // pop
                _stack.pop();

                if (item[0] < (int)a.size() - 1) {
                    //push
                    _stack.push(vector<int>{item[0] + 1, ck});
                    _stack.push(vector<int>{item[0] + 1, -ck});
                } else {
                    cout<<"cur:"<<item[0]<<"min:"<<dinfo[item[0]][0]<<"max:"<<dinfo[item[0]][1]<<endl;
                    d = min(d, dinfo[item[0]][1] - dinfo[item[0]][0]);
                    //d = min(d, get_min_d(B));
                }
                // dinfo
            }
            return d;
        }

        int get_min_d(vector<int>& b) {
            int a = 10001, maxb = 0;
            for (int n : b) {
                if (a > n) a = n;
                if (maxb < n) maxb= n;
            }
            return maxb - a;
        }
};

int main(int argc, char * argv[]) {
    int c = 0;
    Solution * s = new Solution();
    vector<int> l1;
    l1.push_back(0);
    l1.push_back(10);
    c = s->smallestRangeII(l1, 2);
    cout<<c<<endl;
}
