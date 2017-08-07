/**
 * https://leetcode.com/problems/longest-palindromic-substring/solution/
 *
 * this demo is very terrible.
 * dp time O(n^2) space O(n^2)
 *
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>

#define MAX 1000

using namespace std;

int max_l, offset;
int dp[MAX][MAX];

class Solution {
    public:
        string longestPalindrome(string s) {
            int l = s.length();

            for (int i = 0; i < l; ++i) {
                for (int j = i; j < l; ++j) {
                    if (isPalindrome(s.substr(i, j - i + 1), i, j - i + 1)) {
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
        bool isPalindrome(string s, int offset, int length) {
            if (dp[offset][offset + length - 1] < 0) {
                return dp[offset][offset + length - 1] == -1 ? true : false;
            }
            int l = s.length();
            switch (l) {
                case 1:
                    dp[offset][offset + length - 1] = -1;
                    return true;
                    break;
                case 2:
                    if (s[0] == s[1]) {
                        dp[offset][offset + length - 1] = -1;
                        return true;
                    } else {
                        dp[offset][offset + length - 1] = -2;
                        return false;
                    }
                    break;
                default:
                    if (s[0] == s[l - 1] && isPalindrome(s.substr(1, l - 2), offset + 1, l - 2)) {
                        dp[offset][offset + length - 1] = -1;
                        return true;
                    } else {
                        dp[offset][offset + length - 1] = -2; 
                        return false;
                    }
            }
        }
};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    cout<<s->longestPalindrome("babad");
}
