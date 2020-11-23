// https://leetcode.com/problems/fancy-sequence/
typedef long long LL;
const int M = 1e9 + 7;
int qmi(int a, int k, int q) {
    LL res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % q;
        k >>= 1;
        a = (LL)a * a % q;;
    }
    return res;
};
int inv(int a) {
    return qmi(a, M - 2, M);
}

class Fancy {
public:
    vector<LL> nums;
    LL a = 1, b = 0;
    Fancy() {}
    
    void append(int val) {
        nums.push_back(((val - b + M) % M) * inv(a) % M);
    }
    
    void addAll(int inc) {
        b += inc;
        b %= M;
    }

    void multAll(int m) {
        a *= m;
        b *= m;
        a %= M;
        b %= M;
    }
    
    int getIndex(int idx) {
        if (idx >= nums.size()) return -1;
        return (nums[idx] * a + b) % M;
    }
};
