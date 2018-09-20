#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Solution {
    public:
        vector< vector<int> > spiralMatrixIII(int R, int C, int r0, int c0) {
            vector< vector<int> > a;
            int step = 1, num = 1;
            a.push_back(vector<int> {r0, c0});
            while((int)a.size() < R * C)  {
                for (int i = 0; i < step; i++) {
                    c0 += num;
                    if (r0 >= 0 && c0 >= 0 && r0 < R && c0 < C) a.push_back(vector<int> {r0, c0});
                }
                for (int i = 0; i < step; i++) {
                    r0 += num;
                    if (r0 >= 0 && c0 >= 0 && r0 < R && c0 < C) a.push_back(vector<int> {r0, c0});
                }
                num = -num;
                step++;
            }
            return a;
        }
};

int main(int argc, char * argv[]) {
    vector< vector<int> > a;
    Solution * s = new Solution();
    a = s->spiralMatrixIII(1, 4, 0, 0);
    for (int i = 0; i < (int)a.size(); i++) {
        cout<<"i:"<<i<<" r:"<<a[i][0]<<" c:"<<a[i][1]<<endl;
    }
    return 0;
}
