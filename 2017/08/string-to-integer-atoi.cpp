/**
 * https://leetcode.com/problems/string-to-integer-atoi/discuss/
 */
class Solution {
    public:
        int myAtoi(string str) {
            long int i = str.find_first_not_of(' '), sign = 1, r = 0;
            if (str[i] == '-' || str[i] == '+') sign = str[i++] == '-' ? -1 : 1;
            while(str[i] >= '0' && str[i] <= '9') {
                r = r * 10 + (str[i++] - '0');
                if (sign * r > INT_MAX) return INT_MAX;
                if (sign * r < INT_MIN) return INT_MIN;
            }
            return sign * r;
        }
};
