/**
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
}; 

class Solution {
    public:
        vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
            vector<Interval> ans{};
            int i = 0, j = 0, la = A.size(), lb = B.size();
            while (i < la && j < lb) {
                Interval tmp;
                tmp.start = max(A[i].start, B[j].start);
                tmp.end = min(A[i].end, B[j].end);
                if (tmp.start <= tmp.end) {
                    if (ans.size() > 0) {
                        Interval last_it = ans[ans.size() - 1];
                        if (last_it.end == tmp.start) {
                            tmp.start = last_it.start;
                            ans.pop_back();
                            ans.push_back(tmp);
                        } else {
                            ans.push_back(tmp);
                        }
                    } else {
                        ans.push_back(tmp);
                    }
                }
                if (A[i].end == B[j].end) {
                    ++i;
                    ++j;
                    continue;
                } else if (A[i].end < B[j].end) {
                    ++i;
                } else {
                    ++j;
                }
            }
            return ans;
        }
};

int main(int argc, char * argv[]) {
    // [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
    //     Interval(int s, int e) : start(s), end(e) {}
    //vector<Interval> A{Interval(0, 2), Interval(5, 10), Interval(13, 23), Interval(24, 25)};
    vector<Interval> A{};
    vector<Interval> B{Interval(1, 5), Interval(8, 12), Interval(15, 24), Interval(25, 26)};
    Solution * s = new Solution();
    vector<Interval> ans = s->intervalIntersection(A, B);
    for (auto& i : ans) {
        cout<<"{start:"<<i.start<<" end:"<<i.end<<"}"<<endl;
    }
    return 0;
}
