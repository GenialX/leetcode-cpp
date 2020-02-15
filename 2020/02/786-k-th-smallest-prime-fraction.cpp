// https://leetcode.com/problems/k-th-smallest-prime-fraction/

// Binary Search
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double l = 0, r = 1, m = 0;
        int p = 0, q = 1, cnt = 0, n = A.size();;
        while (true) {
            m = l + (r - l) / 2.0;
            cnt = 0, p = 0;
            for (int i = 0, j = 0; i < n; ++i) {
                while (j < n && A[i] > m * A[j]) ++j;
                if (j < n && p * A[j] < q * A[i])
                    p = A[i], q = A[j];
                cnt += n - j;
            }
            if (cnt == K) return {p, q};
            if (cnt < K) l = m;
            else r = m;
        }
    }
};

// Priority Queue
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>> > p;
        for (int i = 0; i < A.size(); ++i) {
            p.push(make_pair(-1 * (double)A[i] / (double)A[A.size() - 1], make_pair(i, A.size() - 1)));
        }
        while (--K) {
            auto e = p.top();
            p.pop();
            if (e.second.first < --e.second.second) {
                e.first = -1 * (double)A[e.second.first] / (double)A[e.second.second];
                p.push(e);
            }
        }
        return {A[p.top().second.first], A[p.top().second.second]};
    }
};
