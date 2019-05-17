#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>

using namespace std;

class Solution {
private:
    int getNum(string& w, int& s) {
        int np = w.find_first_of('.', s);
        if (np == -1) {
            np = w.length();
        }
        int ans = stoi(w.substr(s, np - s));
        s = np + 1;
        return ans;
    }

    bool is_zero(string& w, int& s) {
        for (unsigned int i = s; i < w.length(); ++i) {
            if (w[i] != '.' && w[i] - '0' > 0) return false;
        }
        return true;
    }
public:
    int compareVersion(string w1, string w2) {
        int p1 = 0, p2 = 0, l1 = w1.length(), l2 = w2.length();
        while (p1 < l1 && p2 < l2) {
            int n1 = getNum(w1, p1);
            int n2 = getNum(w2, p2);
            if (n1 > n2) return 1;
            else if (n1 < n2) return -1;
        }
        if (p1 < l1 && is_zero(w1, p1) == false) return 1;
        else if (p2 < l2 && is_zero(w2, p2) == false) return -1;
        else return 0;
    }
};

int main() {
    Solution *s = new Solution();

    ifstream file ("input");
    if (file.is_open()) {
        while (true) {
            if (file.eof()) break;
            string word1, word2;
            getline(file, word1);
            getline(file, word2);
            cout<<"input: w1:"<<word1<<" w2:"<<word2<<endl;
            cout<<"ans:"<<s->compareVersion(word1, word2)<<endl<<endl;
            getline(file, word1);
        }
        file.close();
    }

    return 0;
}
