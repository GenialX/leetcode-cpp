/**
 * https://leetcode.com/problems/trapping-rain-water
 *
 * Related Topics: Array, Two Pointers, Stack
 */
#include <iostream>
#include <vector>

using namespace std;

int calc(int i, int j); // left to right
int calc_last(int i, int j); // right to left

int main() {
    vector<int> nums{0,1,0,2,1,0,1,3,2,1,2,1};

    // declare
    unsigned int i = 0, j = 0, a = 0, index_to_calc = 0;

    // boundary
    if (nums.size() < 3) return a;

    // loop
    while (j <= nums.size() - 1) {
        if (i == j) {
            // do nothing
        } else { // i < j
            if (j - i > 1) {
                // d > 1
                if (nums[j] >= nums[i]) {
                    // to calculate volume
                    a += calc(i, j);
                    index_to_calc = j;
                    // move window
                    i = j;
                }
            } else {
                // d == 1
                if (nums[j] >= nums[i]) {
                    // move window
                    i = j;
                }
            }
        }
        ++j;
    }
    if (index_to_calc < nums.size() - 1) {
        a += calc_last(index_to_calc + 1, nums.size() - 1);
    }

    return 0;
}
