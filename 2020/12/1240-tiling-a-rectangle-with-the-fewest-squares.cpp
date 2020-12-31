class Solution {
public:
    int tilingRectangle(int n, int m) {
        int f[20][20];
        memset(f,0x3f,sizeof f);
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=m;++j) {
                if (i==j) {
                    f[i][j]=1;
                    continue;
                }
                for (int k=1;k<j;++k) f[i][j] = min(f[i][j], f[i][k]+f[i][j-k]);
                for (int k=1;k<i;++k) f[i][j] = min(f[i][j], f[k][j]+f[i-k][j]);
                for (int p=1;p<min(i,j);++p) {
                    for (int k=1;k<p;++k) {
                        if (j-p-k<=0) continue;
                        f[i][j] = min(f[i][j], 2 + f[i-p][p+k] + f[i-p+k][j-p-k] + f[p-k][j-p]);
                    }
                }
            }
        }
        return f[n][m];
    }
};
