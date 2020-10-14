//https://leetcode-cn.com/problems/find-common-characters/
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<vector<int>> hm(2, vector<int>(26, 0));
        int idx = 0;
        for (auto &c : A[0]) {
            hm[idx][c - 'a']++;
        }
        for (int i = 1; i < A.size(); ++i) {
            idx ^= 1;
            for (int i = 0; i < 26; ++i) hm[idx][i] = 0;
            for (auto &c : A[i]) {
                if (hm[idx ^ 1][c - 'a'] == 0 || hm[idx ^ 1][c - 'a'] == hm[idx][c - 'a']) continue;
                hm[idx][c - 'a']++;
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < hm[idx][i]; ++j) {
                ans.emplace_back(1, 'a' + i);
            }
        }
        return ans;
    }
};
