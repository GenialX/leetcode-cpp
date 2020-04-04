//https://leetcode.com/problems/maximum-subarray/
//经典的最大子数组问题
//dp[i + 1] = max(dp[i], dp[i] + nums[i])
//dp[i] 代表包含第 i 元素，并以第 i 元素作为结尾的最大子数组和，那么 dp[i + 1] 的值取决于 max(dp[i], dp[i] + nums[i])
//TC: O(n)，SC: O(n) SC 可优化到 O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n + 1], mvalue = INT_MIN;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = max(dp[i] + nums[i], nums[i]);
            mvalue = max(mvalue, dp[i + 1]);
        }
        return mvalue;
    }
};