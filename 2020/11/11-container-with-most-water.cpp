// O(n) Two Pointer
// https://leetcode-cn.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& H) {
        int i = 0, j = H.size() - 1;
        int res = INT_MIN;
        while (i < j) {
            res = max(res, (j - i) * min(H[i], H[j]));
            if (H[i] < H[j]) ++i;
            else --j;
        }
        return res;
    }
};
