//https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
//起初以为具有最优子结构性质，用DP方式未果。
//发现，是位运算，进行枚举即可。
//位运算操作符的优先级低，导致没有加()出bug
//at 2020.03.14
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> nums;
        for (auto& str : arr) {
            int num = 0;
            for (auto& c : str) {
                if ((num & (1 << (c - 'a'))) > 0) {
                    num = 0;
                    break;
                }
                num = num | (1 <<(c - 'a'));
            }
            nums.push_back(num);
        }
        int ans = INT_MIN;
        for (int i = 0; i < pow(2, arr.size()); ++i) {
            int last = 0;
            bool can = true;
            int cur = 0;
            for (int j = 1; j <= arr.size(); ++j) {
                if (((i >> (j - 1)) & 1) == 1) {
                    if ((last & nums[j - 1]) != 0) {
                        can = false;
                        break;
                    }
                    last = last | nums[j - 1];
                }
            }
            for (int j = 1; can && j <= 26; ++j)
                if (((last >> (j - 1)) & 1) == 1) ++cur;
            ans = max(ans, cur);
        }
        return ans;
    }
};