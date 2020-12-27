class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> p;
        for (int i=0;i<n;++i) {
            if (nums[i]==1) {
                p.push_back(i-p.size());
            }
        }
        int res=INT_MAX;
        vector<int> pre(p.size() + 1, 0);
        for (int i=1;i<=p.size();++i) {
            pre[i] = pre[i-1] + p[i-1];
        }
        for (int i=0;i+k-1<p.size();++i) {
            int j=i+k-1;
            int m=(i+j)/2;
            int left = p[m] * (m-i+1) - (pre[m+1]-pre[i]);
            int right = -p[m] * (j-m) + (pre[j+1]-pre[m+1]);
            res=min(res, left+right);
        }
        return res;
    }
};
