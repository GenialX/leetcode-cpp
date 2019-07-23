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
    int helper(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }
        if (start > end) {
            return 0;
        }
        if (start + 1 == end) {
            return max(nums[start], max(nums[end], nums[start] + nums[end]));
        }
        int m = start + (end - start + 1) / 2;
        int left_max = helper(nums, start, m);
        int right_max = helper(nums, m + 1, end);
        int current_lmax = 0, current_rmax = 0;
        int i = m - 1, t = 0;
        while (i >= start) {
            t += nums[i];
            current_lmax = max(current_lmax, t);
            --i;
        }
        i = m + 1, t = 0;
        while (i <= end) {
            t += nums[i];
            current_rmax = max(current_rmax, t);
            ++i;
        }
        return max(left_max, max(right_max, current_lmax + current_rmax + nums[m]));
    }
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        if (len == 0) return 0;
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        ans = dp[0];
        for (int i = 1; i < len; ++i) {
            dp[i] = (nums[i] + dp[i - 1]) > nums[i] ? nums[i] + dp[i - 1] : nums[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    int maxSubArrayDAC(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution *s = new Solution();
    int n;
    vector<int> nums{};
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        nums.push_back(v);
    }
    cout<<"ans:"<<s->maxSubArrayDAC(nums)<<endl;
    return 0;
}
