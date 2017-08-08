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
        string str;

    public:
        string longestPalindrome(string os) {
            str = os; // os:original string
            int dp[MAX][MAX] = {0};
            int ml = 0, ofs = 0, l = str.length(); // ml:max length ofs:offset
            for (int i = 0; i < l; ++i) {
                for (int j = i; j < l; ++j) {
                    if (isPalindrome(i, j, dp)) {
                        if (j - i + 1> ml) {
                            ofs = i;
                            ml = j - i + 1;
                        }
                    }
                }
            }
            return str.substr(ofs, ml);
        }

    private :
        bool isPalindrome(int s, int e, int dp[MAX][MAX]) { // s:start e:end
            if (dp[s][e] == 0) {
                switch (e - s + 1) {
                    case 1:
                        dp[s][e] = -1;
                        break;
                    case 2:
                        dp[s][e] = str[s] == str[e] ? -1 : -2;
                        break;
                    default:
                        dp[s][e] = (str[s] == str[e] && isPalindrome(s + 1, e - 1, dp))? -1 : -2;
                }
            }
            return dp[s][e] == -1 ? true : false;
        }
};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    cout<<s->longestPalindrome("vommleztyrbrnoij");
}
