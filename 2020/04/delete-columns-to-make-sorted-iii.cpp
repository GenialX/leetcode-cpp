// https://leetcode-cn.com/problems/delete-columns-to-make-sorted-iii/
// 1. DP（区间）
// 2. 逆向思维
// 3. 经典 最长上升子序列 问题
// 
// at 2020.04.18
// TC: O(C^2 * R)
// OC: O(C)
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m = A.size(), n = A[0].size(), t = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                bool can = true;
                for (int k = 0; k < m; ++k) {
                    if (A[k][j] > A[k][i]) {
                        can = false;
                        break;
                    }
                }
                if (can) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        for (auto d : dp) t = max(t, d);
        return n - t;
    }
};
