/**
 * https://leetcode.com/problems/utf-8-validation/solution/
 */

class Solution {
private:
    bool beginWith10(int n) {
        if ((n >> 6) == 2) return true;
        else return false;
    };
public:
    bool validUtf8(vector<int>& data) {
        for (int i = 0; i < data.size();) {
            if ((data[i] >> 7) == 0) {
                // 0xxxxxxx
                i += 1;
            } else if ((data[i] >> 5) == 6) {
                // 110xxxxx
                i += 2;
                if (i > data.size()) return false;
                if (beginWith10(data[i - 1]) == false) return false;
            } else if ((data[i] >> 4) == 14) {
                // 1110xxxx
                i += 3;
                if (i > data.size()) return false;
                if (beginWith10(data[i - 1]) == false || beginWith10(data[i - 2]) == false) return false;
            } else if ((data[i] >> 3) == 30) {
                // 11110xxx
                i += 4;
                if (i > data.size()) return false;
                if (beginWith10(data[i - 1]) == false ||
                    beginWith10(data[i - 2]) == false ||
                    beginWith10(data[i - 3]) == false) return false;
            } else {
                return false;
            }
        }
        return true;
    }
};
