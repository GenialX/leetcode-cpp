#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // 0 1 2 3 right down left up
    vector<int> dir{0, 1, 0, -1, 0};
    int count(vector<vector<int>>& board, int r, int c, int& val, int d) {
        if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size()) return 0;
        if (board[r][c] != val) return 0;
        return 1 + count(board, r + dir[d], c + dir[d + 1], val, d);
    }
    void shake(vector<vector<int>>& board) {}
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int rmax = board.size(), cmax = board[0].size();
        vector<vector<int>>& crushed_board = board;
        for (int r = 0; r < rmax; ++r) {
            for (int c = 0; c < cmax; ++c) {
                if (board[r][c] == 0) continue;
                if (crushed_board[r][c] == -1) continue;
                if (count(board, r, c, board[r][c], 0) + count(board, r, c, board[r][c], 2) - 1 >= 3) {
                    cout<<"h r:"<<r<<"c:"<<c<<" crushed."<<" val:"<<board[r][c]<<endl;
                    crushed_board[r][c] = -1;
                }
                if (count(board, r, c, board[r][c], 1) + count(board, r, c, board[r][c], 3) - 1 >= 3) {
                    cout<<"v r:"<<r<<"c:"<<c<<" crushed."<<" val:"<<board[r][c]<<endl;
                    crushed_board[r][c] = -1; 
                }
            }
        }
        for (int r = 0; r < rmax; ++r) {
            cout<<"{";
            for (int c = 0; c < cmax; ++c) {
                cout<<crushed_board[r][c]<<" ";
            }
            cout<<"}"<<endl;
        }

        return crushed_board;
    }
};

int main(int argc, char * argv[]) {
    // {{110,5,112,113,114},{210,211,5,213,214},{310,311,3,313,314},{410,411,412,5,414},{5,1,512,3,3},{610,4,1,613,614},{710,1,2,713,714},{810,1,2,1,1},{1,1,2,2,2},{4,1,4,4,1014}}
    Solution *s = new Solution();
    vector<vector<int>> board{{110,5,112,113,114},{210,211,5,213,214},{310,311,3,313,314},{410,411,412,5,414},{5,1,512,3,3},{610,4,1,613,614},{710,1,2,713,714},{810,1,2,1,1},{1,1,2,2,2},{4,1,4,4,1014}};
    auto ans = s->candyCrush(board);
    return 0;
}
