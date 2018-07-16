/**
 * https://leetcode.com/problems/4sum/description/
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        vector< vector<int> > rs;
        int l = nums.size();
        for (int i = 0; i < l - 3; ++i) {
            for (int j = i + 1; j < l - 2; j++) {
                int f = j + 1, b = l - 1;
                if (j - i > 1 && nums[j] == nums[j - 1]) continue;
                while (f < b) {
                    if (nums[i] + nums[j] + nums[f] + nums[b] < target) {
                        while (nums[f] == nums[++f]) {}
                    } else if(nums[i] + nums[j] + nums[f] + nums[b] > target) {
                        while (nums[b] == nums[--b]) {}
                    } else {
                        vector<int> tmp = {nums[i], nums[j], nums[f], nums[b]};
                        rs.push_back(tmp);
                        while (nums[f] == nums[++f]) {}
                        while (nums[b] == nums[--b]) {}
                    }
                }
            }
        }
        return rs;
    }
};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(-1);
    vec.push_back(0);
    vec.push_back(-2);
    vec.push_back(2);
    vector< vector<int> > res;
    res = s->fourSum(vec, 0);
    cout<<res.size();
}
