// https://leetcode.com/problems/increasing-triplet-subsequence/

// using the algorithm of Longest Increasing Subsequence O(n log k) -> O(n)
// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        if (n == 0) return false;
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) res.push_back(nums[i]);
            else *it = nums[i];
            if (res.size() >= 3) return true;
        }
        return false;
    }
};

// just two variables to determine
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n1 = INT_MAX, n2 = INT_MAX;
        for (auto n : nums) {
            if (n <= n1) {
                n1 = n;
            } else if (n <= n2) {
                n2 = n;
            } else {
                return true;
            }
        }
        return false;
    }
};