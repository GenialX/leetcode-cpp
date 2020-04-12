//https://leetcode-cn.com/problems/number-of-ways-to-paint-n-x-3-grid/
class Solution {
public:
    int numOfWays(int n) {
        int dp[n][3][3][3];
        memset(dp, 0, sizeof(dp));
        int MOD = 1e9 + 7;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (i != j && j != k) dp[0][i][j][k] = 1;
                }
            }
        }

        for (int r = 1; r < n; ++r) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        for (int i2 = 0; i2 < 3; ++i2) {
                            for (int j2 = 0; j2 < 3; ++j2) {
                                for (int k2 = 0; k2 < 3; ++k2) {
                                    if (i2 != j2 && j2 != k2) {
                                        if (i2 == i || j2 == j || k2 == k) continue;
                                        dp[r][i2][j2][k2] += dp[r - 1][i][j][k];
                                        dp[r][i2][j2][k2] %= MOD;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j) 
                for (int k = 0; k < 3; ++k) {
                    ans += dp[n - 1][i][j][k];
                    ans %= MOD;
                }
        return ans;
    }
};
