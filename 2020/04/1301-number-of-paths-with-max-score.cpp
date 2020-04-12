//https://leetcode-cn.com/problems/number-of-paths-with-max-score/
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int r = board.size(), c = board[0].size();
        int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> dp = vector<vector<pair<int, int>>>(r, vector<pair<int, int>>(c, {0, 0}));
        vector<int> d{-1, 0, -1, -1};
        // first: score second: cnt
        for (int cr = 0; cr < r; ++cr) {
            for (int cc = 0; cc < c; ++cc) {
                if (cr == 0 && cc == 0) {
                    dp[cr][cc] = {0, 1};
                    continue;
                } else if (board[cr][cc] == 'X') {
                    dp[cr][cc] = {0, 0};
                } else {
                    int score = 0, cnt = 0;
                    for (int i = 0; i < 3; ++i) {
                        int nr = cr + d[i];
                        int nc = cc + d[i + 1];
                        if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
                        if (board[nr][nc] == 'X') continue;
                        if (score < dp[nr][nc].first) {
                            score = dp[nr][nc].first;
                            cnt = dp[nr][nc].second;
                        } else if (score == dp[nr][nc].first) {
                            cnt += dp[nr][nc].second;
                            cnt %= MOD;
                        }
                    }
                    if (cnt != 0) {
                        dp[cr][cc].first = score + (board[cr][cc] == 'S' ? 0 : board[cr][cc] - '0');
                        dp[cr][cc].second = cnt;
                    }
                    //cout << cr << " " << cc << " " << dp[cr][cc].first << " " << dp[cr][cc].second << endl;
                }
            }
        }
        return {dp[r - 1][c - 1].first, dp[r - 1][c - 1].second};
    }
};
