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
    bool validTicTacToe(vector<string>& board) {
        int cntx = 0, cnto = 0, winx = 0, wino = 0;
        vector<int> x(3, 0), y(3, 0), d(2, 0);
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                if (board[r][c] == 'X') {
                    ++cntx;
                    x[c] += 1;
                    y[r] += 1;
                    if (r + c == 2) {
                        d[0] += 1;
                    }
                    if (r - c == 0) {
                        d[1] += 1;
                    }
                } else if (board[r][c] == 'O') {
                    ++cnto;
                    x[c] -= 1;
                    y[r] -= 1;
                    if (r + c == 2) {
                        d[0] -= 1;
                    }
                    if (r - c == 0) {
                        d[1] -= 1;
                    }
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            if (x[i] == 3) winx++;
            else if (x[i] == -3) wino++;
            if (y[i] == 3) winx++;
            else if (y[i] == -3) wino++;
            if (i < 2) {
                if (d[i] == 3) winx++;
                else if (d[i] == -3) wino++;
            }
        }

        cout<<cntx<<" "<<cnto<<" "<<winx<<" "<<wino<<endl;
        if (cntx != cnto && cntx - 1 != cnto) return false;
        if (winx && wino) return false;
        if (winx && cntx <= cnto) return false;
        if (wino && cntx != cnto) return false;
        return true;
    }
};

int main() {
    Solution *s = new Solution();
    ifstream file ("input");
    if (file.is_open()) {
        while (true) {
            if (file.eof()) break;
            string line1, line2, line3;
            getline(file, line1);
            getline(file, line2);
            getline(file, line3);
            vector<string> b{line1, line2, line3};
            cout<<line1<<" "<<line2<<" "<<line3<<endl;
            cout<<"ans:"<<s->validTicTacToe(b)<<endl<<endl;
        }
        file.close();
    }
    return 0;
}
