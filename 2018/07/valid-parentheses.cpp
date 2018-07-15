/**
 * https://leetcode.com/problems/valid-parentheses/description/
 */
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            for (string::iterator it = s.begin(); it != s.end(); ++it) {
                if (*it == '(' || *it == '[' || *it == '{') {
                    st.push(*it);
                } else {
                    if (st.empty())  return false;
                    char c = st.top();
                    st.pop();
                    if (*it - c != 1 && *it - c != 2) return false;
                }
            }
            if (!st.empty()) return false;
            return true;
        }

};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    cout<<s->isValid("()")<<endl;
}
