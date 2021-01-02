const int mod = 1e9+7;
class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int f[4][1001][1001];
        int n=S.size();
        S.insert(S.begin(), '0');
        memset(f,0,sizeof f);
        for (int l=1;l<=n;++l) {
            for (int i=1;i+l-1<=n;++i) {
                int j=i+l-1;
                for (int k=0;k<4;++k) {
                    char ch='a'+k;
                    if (l==1) {
                        if (S[i] == ch) {
                            f[k][i][j] = 1;
                            continue;
                        }
                    } else {
                        if (l==2) {
                            if (S[i] == S[j] && S[i] == ch) {
                                f[k][i][j] = 2;
                            } else {
                                f[k][i][j] = f[k][i+1][j] + f[k][i][j-1];
                            }
                        } else {
                            if (S[i] != ch && S[j] != ch) {
                                f[k][i][j] = f[k][i+1][j-1];
                            } else if (S[i] != ch) {
                                f[k][i][j] = f[k][i+1][j];
                            } else if (S[j] != ch) {
                                f[k][i][j] = f[k][i][j-1];
                            } else {
                                f[k][i][j] = 2;
                                for (int m=0;m<4;++m) {
                                    f[k][i][j] += f[m][i+1][j-1];
                                    f[k][i][j] %= mod;
                                }
                            }
                        }
                    }
                }
            }
        }
        return (((f[0][1][n] + f[1][1][n]) % mod + f[2][1][n]) % mod + f[3][1][n]) % mod;
    }
};
