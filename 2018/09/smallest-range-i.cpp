/**
 * https://leetcode.com/problems/smallest-range-i/description/
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Solution {
    public:
        int smallestRangeI(vector<int>& A, int K) {
            int min = 0, max = 0, d = 0;
            if (A.size() == 1) return 0;
            for (int n : A) {
                if (min > n) min = n;
                if (max < n) max = n;
            }
            d = ceil(abs(max - min) / 2);
            if (K >= d) return 0;
            return (d - K) * 2;
        }
};

int main(int argc, char * argv[]) {
    int c = 0;
    Solution * s = new Solution();
    vector<int> l1;
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(6);
    c = s->smallestRangeI(l1, 3);
    cout<<c<<endl;
}
