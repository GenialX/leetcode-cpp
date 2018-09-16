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
        int sumSubarrayMins(vector<int>& A) {
            int mod = 1000000007;
            map<int, map<int, int>> dp;
            map<int, map<int, int>>::iterator it;
            map<int, int>::iterator itt;
            int sum = 0, c_min;
            for (int i = 1; i <= (int)A.size(); i++) {
                for (int j = 1; j <= i; j++) {  
                    if (j == 1) {
                        map<int, int> sub_map;
                        c_min = A[i - 1];
                        sub_map.insert(make_pair(j, c_min));
                        dp.insert(make_pair(i, sub_map));
                        //dp[i][j] = A[i - 1];
                    } else {
                        it = dp.find(i - 1);
                        itt = (it->second).find(j - 1);
                        c_min = min(A[i - 1], itt->second);
                        it = dp.find(i);
                        (it->second).insert(make_pair(j, c_min));
                        dp.insert(make_pair(i, it->second));
                        //dp[i][j] = min(A[i - 1], dp[i - 1][j - 1]);
                    }
                    sum = (sum + c_min) % mod;
                }
            }
            return sum;
        }
};

int main(int argc, char * argv[]) {
    int c = 0;
    Solution * s = new Solution();
    vector<int> l1;
    l1.push_back(81);
    l1.push_back(55);
    l1.push_back(2);
    c = s->sumSubarrayMins(l1);
    cout<<c<<endl;
}
