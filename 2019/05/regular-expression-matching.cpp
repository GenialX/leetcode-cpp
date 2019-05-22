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
private:
    pair<char, int> next(string& s, int& start) {
        char c = s[start++];
        int cnt = 1, i = start;
        for (i = start; i < (int)s.length(); ++i) {
            if (c != s[i]) {
                break;
            } else {
                ++cnt;
            }
        }
        start = i;
        return make_pair(c, cnt);
    }
    bool is_empty(string& p, int& start) {
        // a**a.*
        for (unsigned int i = start; i < p.length(); ++i) {
            if (p[i] == '*' || (p[i] != '*' && i + 1 < p.length() && p[i + 1] == '*')) continue;
            else return false;
        }
        return true;
    }
    bool check(string& p, int& start, pair<char, int> pci) {
        // a*.*
        int spark = 0, character = 0;
        for (unsigned int i = start; i < p.length(); ++i) {
            if (p[i] == '*' && p[i - 1] == '*') continue;
            if (p[i] != pci.first && p[i] != '*' && p[1] != '.') {
                start = i;
                break;
            } else {
                if (p[i] == '*') {
                    ++character;
                } else {
                    ++spark;
                }
            }
        }
        int min_cnt = (character <= spark) ? 0 : character - spark;
        int max_cnt = (spark > 0) ? INT_MAX : character;
        return (pci.second >= min_cnt && pci.second <= max_cnt) ? true : false;
    }
public:
    bool isMatch(string s, string p) {
        // abc a*abcc*
        int p1 = 0, len = s.length(), p2 = 0;
        while (p1 < len) {
            cout<<"p1:"<<p1<<endl;
            pair<char, int> pci = next(s, p1);
            cout<<"find pci:"<<pci.first<<" cnt:"<<pci.second<<" p1:"<<p1<<endl;
            if (check(p, p2, pci) == false) return false;
            cout<<" p2:"<<p2<<endl;
        }
        if (is_empty(p, p2) == true) return true;
        return false;
    }
};

int main() {
    Solution *s = new Solution();

    ifstream file ("input");
    if (file.is_open()) {
        while (true) {
            if (file.eof()) break;
            string word1, word2;
            getline(file, word1);
            getline(file, word2);
            cout<<"input: s:"<<word1<<" p:"<<word2<<endl;
            bool ans = s->isMatch(word1, word2);
            cout<<"ans:"<<ans<<endl;
            getline(file, word1);
        }
        file.close();
    }

    return 0;
}
