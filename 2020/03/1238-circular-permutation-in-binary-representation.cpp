//https://leetcode-cn.com/problems/circular-permutation-in-binary-representation/
//https://zh.wikipedia.org/wiki/%E6%A0%BC%E9%9B%B7%E7%A0%81
//1. 生成格雷码序列
//2. 反转数组（三次反转）
class Solution {
public:
    vector<int> circularPermutation(int width, int start) {
        vector<int> ans;
        int n = pow(2, width), p = 0;
        for(int i = 0; i < n; ++i) {
            ans.push_back(i ^ (i >> 1));
            if ((i ^ (i >> 1)) == start) p = i;
        }
        reverse(ans.begin(), ans.begin() + p);
        reverse(ans.begin(), ans.end());
        reverse(ans.begin(), ans.begin() + n - p);
        return ans;
    }
};