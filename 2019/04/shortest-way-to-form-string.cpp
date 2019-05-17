#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int shortest(string source, string target) {
            if (source == target) return 0;
            if (source.length() == 0 && target.length() == 0) return 0;
            if (source.length() == 0 && target.length() > 0) return -1;
            if (source.length() > 0 && target.length() == 0) return source.length();
            unordered_set<char> ss;
            for (unsigned int i = 0; i < source.length(); ++i) {
                ss.insert(source[i]);
            }
            for (unsigned int i = 0; i < target.length(); ++i) {
                if (ss.find(target[i]) == ss.end()) return -1;
            }
            unsigned int ti = 0;
            unsigned int ans = 0;
            while (ti < target.length()) {
                string sub_s = "";
                findLongestS(source, target, ti, sub_s);
                ++ans;
            }

            return ans;
        }
    private:
        void findLongestS(string& source, string& target, unsigned int& ti, string& sub_s) {
            unsigned int si = 0, tl = target.length(), sl = source.length();
            while (ti < tl && si < sl) {
                if (source[si] == target[ti]) {
                    sub_s += target[ti];
                    ++si, ++ti;
                } else {
                    ++si;
                }
            }
            //cout<<"source:"<<source<<" target:"<<target<<" ti:"<<ti<<" sub_s:"<<sub_s<<endl;
        }
};

int main(int argc, char * argv[]) {
    int c = 0;
    Solution * s = new Solution();
    string source = "abc", target = "abcbc";
    c = s->shortest(source, target);
    source = "abc", target = "acdbc";
    cout<<c<<endl;
    c = s->shortest(source, target);
    cout<<c<<endl;
    source = "xyz", target = "xzyxz";
    c = s->shortest(source, target);
    cout<<c<<endl;
    source = "abcdefg", target = "bcegabcbcdefg";
    c = s->shortest(source, target);
    cout<<c<<endl;
}
