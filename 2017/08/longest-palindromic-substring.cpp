/**
 * https://leetcode.com/problems/longest-palindromic-substring/solution/
 *
 * this demo:using the dp method, time O(n^2) space O(n^2)
 *
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>

#define MAX 1001

using namespace std;

class Solution {
    private:
        string s;

    public:
        string longestPalindrome(string ori_s) {
            s = ori_s;
            int dp[MAX][MAX] = {0};
            int max_l = 0, offset = 0, l = s.length();
            for (int i = 0; i < l; ++i) {
                for (int j = i; j < l; ++j) {
                    if (isPalindrome(i, j, dp)) {
                        if (j - i + 1> max_l) {
                            offset = i;
                            max_l = j - i + 1;
                        }
                    }
                }
            }
            return s.substr(offset, max_l);
        }

    private :
        bool isPalindrome(int start, int end, int dp[MAX][MAX]) {
            if (dp[start][end] == 0) {
                switch (end - start + 1) {
                    case 1:
                        dp[start][end] = -1;
                        break;
                    case 2:
                        dp[start][end] = s[start] == s[end] ? -1 : -2;
                        break;
                    default:
                        dp[start][end] = (s[start] == s[end] && isPalindrome(start + 1, end - 1, dp))? -1 : -2;
                }
            }
            return dp[start][end] == -1 ? true : false;
        }
};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    cout<<s->longestPalindrome("vommleztyrbrnoij");
}
