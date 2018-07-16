/**
 * https://leetcode.com/problems/generate-parentheses/description
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rs;
        generateParenthesisDFS(n, n, "", rs);
        return rs;
    }
    void generateParenthesisDFS(int lsize, int rsize, string out, vector<string> &rs) {
        if (lsize == 0 && rsize == 0) {
            rs.push_back(out);
            return;
        }
        if (lsize > rsize) return;
        if (lsize > 0) generateParenthesisDFS(lsize - 1, rsize, out + "(", rs);
        if (rsize > 0) generateParenthesisDFS(lsize, rsize - 1, out + ")", rs);
        return;
    }
};

int main(int arvc, char *argv[]) {
    Solution *s = new Solution();
    vector<string> v = s->generateParenthesis(3);
    cout<<v.size()<<endl;
}

