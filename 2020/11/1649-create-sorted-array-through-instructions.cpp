const int N = 1e5 + 10, MOD = 1e9 + 7;
int c[N];
class Solution {
public:
    int query(int x) {
        int ans = 0;
        for (; x; x -= x & -x) ans += c[x];
        return ans;
    }
    void update(int x, int y) {
        for (; x < N; x += x & -x) c[x] += y;
    }
    int createSortedArray(vector<int>& IS) {
        memset(c, 0, sizeof c);
        int ans = 0;
        for (int i = 0; i < IS.size(); ++i) {
            int l = query(IS[i] - 1), r = i - query(IS[i]);
            ans += min(l, r);
            ans %= MOD;
            update(IS[i], 1);
        }
        return ans;
    }
};
