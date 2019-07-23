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
    int mySqrt(int n) {
        if (n == 0) return 0;
        int l = 1, h = n / 2 + 1, m = l;
        while (l < h) {
            cout<<" l:"<< l <<" h:"<<h<<endl;
            // can not use the format: m = l / 2 + h / 2;
            // when could use this format to avoid overflow?
            m = (l + h) >> 1;
            if (m * m <= n) {
                l = m;
            } else {
                h = m - 1;
            }
            if (l == h - 1) {
                if (h * h <= n) l = h;
                else h = l;
            }
        }
        return l;
    }
};

int main() {
    Solution *s = new Solution();
    for (int i = 0; i < 10; ++i)  cout << "input:" << i << " ans:" << s->mySqrt(i) << endl;
    return 0;
}
