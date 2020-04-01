//https://leetcode-cn.com/problems/max-submatrix-lcci/
//1. 前缀和 & 最大子数组扩展（动态规划）
//at 2020.03.31
//时间复杂度：O(r ^ 2 * c) 空间复杂度：O(r * c)
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> accum = vector(c, vector(r + 1, 0));
        for (int cc = 0; cc < c; ++cc) {
            for (int cr = 0; cr < r; ++cr) {
                accum[cc][cr + 1] += accum[cc][cr] + matrix[cr][cc];
            }
        }
        int mvalue = INT_MIN;
        vector<int> ans(0, 4);
        for (int sr = 0; sr < r; ++sr) {
            for (int cr = sr; cr < r; ++cr) {
                int marr = 0, marri = 0;
                for (int cc = 0; cc < c; ++cc) {
                    if (marr > 0) {
                        marr = marr + accum[cc][cr + 1] - accum[cc][sr];
                    } else {
                        marr = accum[cc][cr + 1] - accum[cc][sr];
                        marri = cc;
                    }
                    if (marr > mvalue) {
                        mvalue = marr;
                        ans = {sr, marri, cr, cc};
                    }
                }
            }
        }
        return ans;
    }
};