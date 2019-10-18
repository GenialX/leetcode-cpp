#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define PB push_back
#define MP make_pair

using namespace std;

const double eps = 1e-8;

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;

class Solution {
public:
    string smallestSubsequence(string text) {
        int len = text.size();
        unordered_map<char, int> memo;
        for (int i = len - 1; i >= 0; --i) {
            if (memo.find(text[i]) == memo.end()) {
                memo[text[i]] = i;
            }
        }
        string ans = "";
        stack<char> st;
        unordered_map<char, int> vis{};
        int i = 0;
        while (i < len) {
            if (vis[text[i]] == 0) {
                if (st.size() > 0 && st.top() > text[i] && memo[st.top()] > i) {
                    vis[st.top()] = 0;
                    st.pop();
                } else {
                    st.push(text[i]);
                    vis[text[i]] = 1;
                    ++i;
                }
            } else {
                ++i;
            }
        }
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
// st  a d b c
// ans 
// cdadabcc -> adbc
int main() {
    Solution *s = new Solution();
    cout << s->smallestSubsequence("cdadabcc") << endl;
    return 0;
}
/**
 * Find the index of last occurrence for each character.
 * Use a stack to keep the characters for result.
 * Loop on each character in the input string S,
 * if the current character is smaller than the last character in the stack,
 * and the last character exists in the following stream,
 * we can pop the last character to get a smaller result.
 */
