//https://leetcode-cn.com/problems/paths-with-sum-lcci/
//1. 题意都看错了，以为是求子树，人家是要求子路径，就这脑子是不是被门挤了？
//2. 回溯、前缀和
//
//时间复杂度：O(n)
//空间复杂度：O(logn)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> accu;
    int target, ans = 0;
    void helper(TreeNode* node, int sum) {
        if (node == nullptr) return;
        sum += node->val;
        if (accu[sum - target]) ans += accu[sum - target];
        accu[sum]++;
        helper(node->left, sum);
        helper(node->right, sum);
        accu[sum]--;
    }
    int pathSum(TreeNode* root, int t) {
        target = t, accu[0] = 1;
        helper(root, 0);
        return ans;
    }
};