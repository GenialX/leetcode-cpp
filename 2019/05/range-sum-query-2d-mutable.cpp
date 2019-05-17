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

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& _matrix) {
    }

    void update(int r, int c, int v) {
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        if (rm == 0 || cm == 0) return 0;
        return sum(r2 + 1, c2 + 1) + sum(r1, c1) - sum(r2 + 1, c1) - sum(r1, c2 + 1);
    }
};

int main(int argc, char * argv[]) {

    vector<vector<int>> matrix;

    string line;
    getline(cin, line);
    do {
        if (line == "update" || line == "sumRegion") break;
        stringstream stringin(line);
        int n;
        vector<int> ns{};
        while (stringin >> n) {
            ns.push_back(n);
        }
        matrix.push_back(ns);
        getline(cin, line);
    } while (line.length() > 0);
    Solution *s = new NumMatrix(matrix);

    do {
        stringstream stringin(line);
        vector<int> pos{};
        string pos_line = getline(cin, pos_line);
        int pos_v = 0;
        for (int i = 0; i < pos_line.length(); ++i) {
            if (pos_line[i] == 0) {
                pos.push_back(pos_v);
                pos_v = 0;
            } else {
                pos_v = pos_v * 10 + (pos_line[i] - '0');
            }
        }
        if (line == "update") {
            s->update(pos_v[0], pos_v[1], pos_[2]);
        } else {
            cout<<"regionSum:"<<s->regionSum(pos_v[0], pos_v[1], pos_v[2], pos_v[3])<<endl;
        }
    } while (line.length() > 0);

    return 0;
}
