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
    vector<int> d{0, -1, 0, 1, 0}; // left up right down 0 left, 1 up, 2 right, 3 down
    unordered_map<int, unordered_set<int>> vis;
    queue<vector<int>> q;
    vector<int> getNextPos(vector<int> start, int dtype, int mr, int mc, vector<vector<int>>& maze) {
        cout<<"start r:"<<start[0]<<" c:"<<start[1]<<" dtype:"<<dtype<<" ";
        vector<int> ans(3, 0);
        int nr = start[0], nc = start[1];
        int count = 0;
        while (nr + d[dtype] >= 0 && nr + d[dtype] < mr && nc + d[dtype + 1] >= 0 && nc + d[dtype + 1] < mc && maze[nr + d[dtype]][nc + d[dtype + 1]] == 0) {
            nr = nr + d[dtype];
            nc = nc + d[dtype + 1];
            ++count;
            //cout<<"nr:"<<nr<<" nc:"<<nc<<" maze:"<<maze[nr][nc]<<endl;
        }
        ans[0] = nr;
        ans[1] = nc;
        ans[2] = count;
        cout<<"return r:"<<ans[0]<<" c:"<<ans[1]<<endl;
        return ans;
    }
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        q.push(vector<int>{start[0], start[1], 0});
        int mr = maze.size(), mc = maze[0].size();
        int len = q.size();
        int i = 0;
        int ans = INT_MAX;
        while (i < len) {
            cout<<"i:"<<i<<endl;
            auto pa = q.front();
            q.pop();
            if (pa[0] == destination[0] && pa[1] == destination[1]) {
                ans = min(ans, pa[2]);
            }
            vis[pa[0]].insert(pa[1]);
            for (int j = 0; j < 4; ++j) {
                cout<<"j:"<<j<<" ";
                auto nextpos = getNextPos({pa[0], pa[1]}, j, mr, mc, maze);
                int nr = nextpos[0], nc = nextpos[1];
                if (nr == pa[0] && nc == pa[1]) continue;
                if (nr < 0 || nc < 0 || nr >= mr || nc >= mc) continue;
                if (vis.find(nr) != vis.end() && vis[nr].find(nc) != vis[nr].end()) continue;
                cout<<"push to q:"<<nr<<" "<<nc<<endl;
                q.push({nr, nc, nextpos[2] + pa[2]});
            }
            if (i == len - 1) {
                i = 0;
                len = q.size();
                cout<<"new len:"<<len<<endl;
            } else {
                ++i;
                cout<<"i++"<<endl;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<int>> maze;
    vector<int> start(2, 0), destination(2, 0);
    int r, c;
    cin >> r >> c;
    maze = vector<vector<int>>(r, vector<int>(c, 0));
    for (int cr = 0; cr < r; ++cr) {
        for (int cc = 0; cc < c; ++cc) {
            int n = 0;
            cin >> n;
            maze[cr][cc] = n;
            //cout<<"get number:"<<n<<" ";
        }
    }
    cin >> start[0] >> start[1] >> destination[0] >> destination[1];
    cout<<s->shortestDistance(maze, start, destination)<<endl;
    return 0;
}
