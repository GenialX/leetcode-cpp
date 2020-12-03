#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int dp[maxn], n;
int idx[maxn];
void print_a(int *a, int n) {
    cout<<"{";
    for(int i=0;i<n;++i) cout<<"i:"<<i<<" a[i]:"<<a[i]<<" ";
    cout<<"}"<<endl;
}
class Solution {
public:
    int findP(int st, vector<int>& et) {
        int l=0,r=n-1,m;
        while(l<r) {
            m=l+r+1>>1;
            if(et[idx[m]]<=st) {
                l=m;
            }else{
                r=m-1;
            }
        }
        return l;
    }
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
        memset(dp,0,sizeof dp);
        n = st.size();
        for(int i=0;i<n;++i) {
            idx[i]=i;
        }
        sort(idx, idx+n, [&](int&a, int &b) -> bool {return et[a] < et[b];});
        for (int i=1;i<=n;++i) {
            int j = findP(st[idx[i-1]], et);
            dp[i] = max(p[idx[i-1]], dp[i-1]);
            if(et[idx[j]] <= st[idx[i-1]]) {
                dp[i] = max(dp[i], dp[j+1]+p[idx[i-1]]);
            }
        }
        return dp[n];
    }
};
int main() {
    auto s=new Solution();
    vector<int>a{1,2,3,4,6},b{3,5,10,6,9},c{20,20,100,70,60};
    cout<<s->jobScheduling(a,b,c)<<endl;
    return 0;
}

