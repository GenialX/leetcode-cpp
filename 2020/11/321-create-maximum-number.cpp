#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int st[maxn], idx; // from 1 index
class Solution {
public:
    vector<int> getMaxSeq(vector<int>& nums, int k) {
        if (nums.size() < k) return {};
        int n = nums.size();
        int rm = n-k;
        idx = 0;
        for(int i=0;i<n;++i) {
            auto t=nums[i];
            while(idx>=1 && rm && st[idx] < t) {
                --idx;
                --rm;
            }
            if (idx < k) {
                st[++idx] = t;
            } else {
                --rm;
            }
        }
        vector<int> ans;
        for (int i=1;i<=idx;++i) {
            ans.push_back(st[i]);
        }
        return ans;
    }
    int cmp(vector<int>& n1, int p1, vector<int>& n2, int p2) {
        int l1 = n1.size(), l2 = n2.size();
        int i = p1, j = p2;
        while(i < l1 && j < l2) {
            if (n1[i] != n2[j]) return n1[i] - n2[j];
            ++i;++j;
        }
        return (l1-i)-(l2-j);
    }
    vector<int> merge(vector<int>& n1, vector<int>& n2) {
        vector<int> ans;
        int i = 0, j = 0;
        while(i < n1.size() && j < n2.size()) {
            if (cmp(n1, i, n2, j) > 0) {
                ans.push_back(n1[i++]);
            } else {
                ans.push_back(n2[j++]);
            }
        }
        while(i < n1.size()) {
            ans.push_back(n1[i++]);
        }
        while(j < n2.size()) {
            ans.push_back(n2[j++]);
        }
        return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        for (int k1=0;k1<=k;++k1) {
            int k2 = k - k1;
            if (k1 > nums1.size() || k2> nums2.size()) continue;
            auto n1=getMaxSeq(nums1,k1);
            auto n2=getMaxSeq(nums2,k2);
            auto n3=merge(n1,n2);
            if (cmp(n3, 0, ans, 0) >= 0) ans=n3;
        }
        return ans;
    }
};
