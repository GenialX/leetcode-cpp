const int maxn = 16;
int f[1<<maxn],g[1<<maxn]; // g>=0 合法，代表差值（兼容性），f[i] 以 i 二进制形式下表示的集合，其最优值是f[i]
int idx[maxn];
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n=nums.size();
        memset(f,0x3f,sizeof f);
        memset(g,-1,sizeof g);
        for(int i=1;i<1<<n;++i) {
            if (__builtin_popcount(i) == n/k) {
                int t=0;
                for (int j=0;j<n;++j) {
                    if ((i>>j)&1) idx[t++] = nums[j];
                }
                sort(idx, idx+t);
                int miv=idx[0], mav=idx[0];
                bool eq=false;
                for(int j=0;j<t;++j) {
                    miv=min(miv,idx[j]);
                    mav=max(mav,idx[j]);
                    if(j<t-1 && idx[j]==idx[j+1]) eq=true;
                }
                if (!eq) g[i]=mav-miv;
            }
//            printf("i:%d, g[i]:%d\n", i, g[i]);
        }
        f[0]=0;
        for (int i=0;i<(1<<n);++i) {
            for(int j=i;j;j=(j-1)&i) {
                if (g[j]!=-1) {
                    f[i]=min(f[i], f[i-j] + g[j]);
  //                  printf("i:%d, j:%d, g[j]:%d, f[i]:%d\n", i, j, g[j], f[i]);
                }
            }
        }
        return f[(1<<n) - 1] == 0x3f3f3f3f ? -1 : f[(1<<n) - 1];
    }
};
