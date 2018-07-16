/**
 * https://leetcode.com/contest/weekly-contest-93/problems/advantage-shuffle/
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    public:
        vector<int> advantageCount(vector<int>& A, vector<int>& B) {
            sort(A.begin(), A.end());
            vector<int> C;
            int A_pos = -1;
            for (unsigned long i = 0; i < B.size(); ++i) {
                A_pos = -1;
                for (unsigned long j = 0; j < A.size(); ++j) {
                    if (A[j] == -1) continue;
                    if (A[j] > B[i]) {
                        A_pos = j;
                        break;
                    }
                }
                if (A_pos == -1) {
                    for (unsigned long j = 0; j < A.size(); ++j) {
                        if (A[j] != -1) {
                            A_pos = j;
                            break;
                        }
                    }
                }
                C.push_back(A[A_pos]);
                A[A_pos] = -1;
            }
            return C;
        }
};


int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    vector<int> a = {2,7,11,15};
    vector<int> b = {1,10,4,11};
    vector<int> c;
    c = s->advantageCount(a,b);
}
