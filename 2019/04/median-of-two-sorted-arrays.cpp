/**
 * https://leetcode.com/problems/median-of-two-sorted-arrays/solution/
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int m = nums1.size(), n = nums2.size();
        int l1 = 0, r1 = m - 1, l2 = 0, r2 = n - 1;
        int i = m / 2, j = (m + n) / 2 - i + 1;
        while (true) {
            if (nums1[i - 1] <= nums2[j] && nums1[j - 1] <= nums2[i]) {
                return (max(nums1[i - 1], nums2[j - 1]) + min(nums1[i], nums2[j])) * 1.0 / 2;
            }
            if (nums1[i - 1] > nums2[j]) {
                --i, ++j;
            } else if (nums2[j - 1] > nums1[i]) {
                --j, ++i;
            }
        }

        return -1.0;
    }
};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    vector<int> a{1, 2, 3}, b{2, 3, 4};
    return s->findMedianSortedArrays(a, b);
}
