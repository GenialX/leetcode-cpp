#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string convert(string s, int n) {
            if (n == 1) return s;
            int l = s.length(), k = 0, c_i = 0;
            string r_s = ""; 
            for (int i = 0; i < n; ++i) {
                while(true) {
                    if (i == 0 || i == n - 1) c_i = 2 * k * (n - 1) + i;
                    else c_i = (k % 2 == 0) ? k * (n - 1) + i : (k + 1) * (n - 1) - i;
                    if (c_i >= l) break;
                    r_s.append(s, c_i, 1); 
                    ++k;
                }   
                k = 0;
            }   
            return r_s;
        }
};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    cout<<s->convert("PAYPALISHIRING", 3);
}
