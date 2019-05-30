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
    // ab dhasbafsdf
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> cop1;
        for (auto& c : s1) {
            ++cop1[c];
        }
        unsigned int l = 0, r = 0, s2len = s2.length();
        while (l < s2len) {
            if (cop1.find(s2[l]) != cop1.end()) {
                --cop1[s2[l]];
                if (cop1[s2[l]] == 0) {
                    cop1.erase(s2[l]);
                }
                break;
            }
            ++l;
        }
        if (l == s2len) return false;
        r = l + 1;
        for (; r < s2len;) {
            if (cop1.find(s2[r]) != cop1.end()) {
                --cop1[s2[r]];
                if (cop1[s2[r]] == 0) {
                    cop1.erase(s2[r]);
                }
                ++r;
                if (cop1.size() == 0) return true;
            } else {
                if (l < r) {
                    ++cop1[s2[l]];
                    ++l;
                } else {
                    ++l;
                    ++r;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution *s = new Solution();
    string s1, s2;
    cin >> s1;
    cin >> s2;
    bool ans = s->checkInclusion(s1, s2);
    if (ans) cout << "true" << endl;
    else cout << " false " << endl;
}

