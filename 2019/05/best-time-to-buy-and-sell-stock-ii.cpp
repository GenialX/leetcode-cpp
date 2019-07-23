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
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> h(len, 0);
        h[len - 1] = len - 1;
        //cout<<"i:"<<len - 1<<" h:"<<h[len - 1]<<endl;
        for (int i = len - 2; i >= 0; --i) {
            if (prices[i] < prices[i + 1]) {
                h[i] = h[i + 1];
            } else {
                h[i] = i;
            }
            //cout<<"i:"<<i<<" h:"<<h[i]<<endl;
        }
        int i = 0, ans = 0;
        //cout<<endl;
        while (i < len) {
            //cout<<"i:"<<i<<endl;
            if (h[i] == i) {
                ++i;
            } else {
                ans += prices[h[i]] - prices[i];
                i = h[i] + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution *s = new Solution();
    int n;
    cin >> n;
    vector<int> prices;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        prices.push_back(v);
    }
    cout << " ans:" << s->maxProfit(prices) << endl;;
    return 0;
}
