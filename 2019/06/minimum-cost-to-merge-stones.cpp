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
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if (k > n) return 0;
        if ((n - 1) % (k - 1)) return -1;

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + stones[i];
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = k; l <= n; ++l) {
            for (int i = 0; i < n - l + 1; ++i) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (int m = i; m < j; m += k - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
                }
                if ((j - i) % (k - 1) == 0) {
                    dp[i][j] += prefix[j + 1] - prefix[i];
                }
            }
        }
        
        return dp[0][n - 1];
    }
};

int main() {
    Solution *s = new Solution();
    int n, k;
    vector<int> stones;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        stones.push_back(s);
    }
    cin >> k;
    cout<<"n:"<<n<<" k:"<<k<<endl;
    cout<<s->mergeStones(stones, k)<<endl;
    return 0;
}
