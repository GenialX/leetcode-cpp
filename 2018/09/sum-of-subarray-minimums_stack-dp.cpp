/**
 * https://leetcode.com/problems/sum-of-subarray-minimums/
 */
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

class Solution {
    stack<pair<int, int>> st;
    public:
    int next(int price) {
        int d = 1;
        while (!st.empty() && st.top().first >= price) {
            d += st.top().second;;
            st.pop();
        }
        st.push(make_pair(price, d));
        return d;
    }
    int sumSubarrayMins(vector<int>& A) {
        int a = 0, l = A.size(), d, mod = 1000000007;
        int dp[A.size()];
        for (int i = 0; i < l; i++) {
            d = next(A[i]);
            //dp[i] = A[i] * d + dp[i - d];
            dp[i] = (A[i] * d) % mod;
            if (i - d >= 0) dp[i] = (dp[i] + dp[i - d]) % mod;
            a = (a + dp[i]) % mod;
        }
        return a;
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
