//https://leetcode.com/problems/stone-game-iii/
//记忆化递归 + 备忘录
//时间复杂度：O(n)
//空间复杂度：O(n)
//at 2020.04.05
class Solution {
public:
    unordered_map<int, int> memo;
    vector<int> accum;
    int helper(vector<int>& S, int s) {
        if (memo.find(s) != memo.end()) return memo[s];
        int ans = INT_MIN, cur = 0;
        for (int i = 1; i <= 3 && s + i - 1 < S.size(); ++i) {
            int other = helper(S, s + i);
            cur = accum[s] - other;
            ans = max(ans, cur);
        }

        return memo[s] = (ans == INT_MIN ? 0 : ans);
    }
    string stoneGameIII(vector<int>& S) {
        int n = S.size();
        accum = vector<int>(n + 1, 0);
        int sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum += S[i];
            accum[i]  = accum[i + 1] + S[i];
        }
        int get = helper(S, 0);
        if (get > sum - get) return "Alice";
        else if (get == sum - get) return "Tie";
        else return "Bob";
    }
};
