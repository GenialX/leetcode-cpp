//https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target/
class Solution {
private:
    int getV(vector<int>& arr, int m) {
        int ans = 0;
        for (auto& n :arr) {
            if (n <= m) {
                ans += n;
            } else {
                ans += m;
            }
        }
        return ans;
    }
public:
    int findBestValue(vector<int>& arr, int target) {
        int l = 0, h = 1e5;
        int ans = INT_MAX, d = INT_MAX;
        while (l <= h) {
            int m = l + (h - l) / 2;
            int v = getV(arr, m);
            //cout << l << " " << h << " "  << m << " " << v << endl;
            if (v < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
            if (abs(v - target) < d) {
                d = abs(v - target);
                ans = m;
            } else if (abs(v - target) == d) {
                ans = min(ans, m);
            }
        }
        return ans;
    }
};
