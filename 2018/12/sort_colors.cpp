/**
 * https://leetcode.com/problems/sort-colors/
 *
 * 分类讨论，很为重要！
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0, p2 = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == 2) {
                ++p2;
            } else if (nums[i] == 1) {
                if (p1 == p2) {
                    nums[p1++] = nums[i];
                    ++p2;
                } else if (p1 < p2) {
                    int value = nums[p2]; // p2 == i
                    nums[p2++] = nums[p1];
                    nums[p1++] = value;
                }
            } else if (nums[i] == 0) {
                if (p0 == p1 && p1 == p2) {
                    nums[p0] = nums[i];
                    ++p0;
                    ++p1;
                    ++p2;
                } else if(p0 == p1 && p1 < p2) {
                    int value = nums[p2];
                    nums[p2++] = nums[p0];
                    nums[p0] = value;
                    ++p1;
                    ++p0;
                } else if(p0 < p1 && p1 < p2) {
                    int value = nums[p2];
                    nums[p2++] = nums[p1];
                    nums[p1++] = nums[p0];
                    nums[p0++] = value;
                }
            }
        }
    }
};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    vector<int> nums{0,2,1,1,1,2,2,2,0,0};
    s->sortColors(nums);
    for (auto x : nums) {
        cout<<x<<" ";
    }
    return 0;
}
