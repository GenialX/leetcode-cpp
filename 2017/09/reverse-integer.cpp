/**
 * https://leetcode.com/problems/reverse-integer/description/
 */
#include <iostream>

using namespace std;

class Solution {
    public:
        int reverse(int x) {
            long int r = 0;
            while (x) {
                r = r * 10 + x % 10;
                x /= 10;
            }
            return (r > INT_MAX || r < INT_MIN) ? 0 : r;
        }
};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    cout<<s->reverse(-123);
}
