// https://leetcode.com/problems/k-th-smallest-prime-fraction/


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
