//https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
//1. 栈
//时间复杂度：O(n)
//空间复杂度：O(1)
//at 2020.04.01
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n, 0);
        int maxd = INT_MIN, cnt = 0;
        for (auto& c : seq) {
            if (c == '(') ++cnt;
            else --cnt;
            maxd = max(maxd, cnt);
        }
        int mind = maxd / 2 + 1;
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            char c = seq[i];
            if (c == '(') {
                st.push(i);
            } else {
                if (st.size() >= mind) {
                    ans[i] = 1;
                    ans[st.top()] = 1;
                }
                st.pop();
            }
        }
        return ans;
    }
};