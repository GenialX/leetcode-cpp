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
    int minKBitFlips(vector<int>& A, int K) {
        int ans = 0, cnt = 0;
        vector<int> close(A.size(), 0);
        for (int i = 0; i < A.size(); ++i) {
            if (close[i]) --cnt;
            if ((cnt % 2 == 0 && A[i] == 0) || (cnt % 2 == 1 && A[i] == 1)) {
                ++cnt;
                ++ans;
                if (i + K > A.size()) return -1;
                if (i + K < A.size()) ++close[i + K];
            }
        }
        return ans;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> A;
    int K = 0;

    ifstream file ("input");
    if (file.is_open()) {
        while (true) {
            string line1, line2;
            getline(file, line1);
            getline(file, line2);
            A.clear();
            if (file.eof()) break;
            stringstream input(line1);
            string tmp;
            while (getline(input, tmp, ',')) {
                A.push_back(atoi(tmp.c_str()));
            }
            K = atoi(line2.c_str());
            cout << s->minKBitFlips(A, K) << endl;
        }
        file.close();
    }
    return 0;
}
