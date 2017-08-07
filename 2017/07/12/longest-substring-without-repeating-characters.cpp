/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description
 *
 * dp
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

#define MAX 1000000001

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> dp;
        int max_length = -1, cur_length = 0, cur_offset = 0, length = s.size(), last_offset = 0;
        for (int i = 1; i < length + 1; ++i) {
            map<char, int>::iterator it = dp.find(s[i - 1]);
            if (it != dp.end() && it->second >= cur_offset) {
                last_offset = it->second;
                cur_offset = last_offset + 1;
                cur_length = i - cur_offset + 1;
            } else {
                if (++cur_length > max_length) max_length = cur_length;
                dp.insert(pair<char, int>(s[i - 1], i));
            }
            it->second = i;// re-write the current pos for the cur char
        }
        return max_length > 0 ? max_length : 0;
    }
};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    cout<<s->lengthOfLongestSubstring("qwnfenpglqdq");
}
