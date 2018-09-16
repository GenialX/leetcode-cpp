/**
 * https://leetcode.com/problems/sum-of-subarray-minimums/
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Solution {
    public:
        int A(vector<int>& A) {
            return 0;
        }
};

int main(int argc, char * argv[]) {
    int c = 0;
    Solution * s = new Solution();
    vector<int> l1;
    l1.push_back(81);
    l1.push_back(55);
    l1.push_back(2);
    c = s->sumSubarrayMins(l1);
    cout<<c<<endl;
}
