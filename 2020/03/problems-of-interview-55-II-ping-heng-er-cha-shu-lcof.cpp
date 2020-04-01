//https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
//1. bt dfs 中序遍历
//at 2020.03.31
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
    int helper(TreeNode* node, bool &isB) {
        if (node == nullptr) return 0;
        int ans = 0;
        int l = helper(node->left, isB);
        int r = helper(node->right, isB);
        if (abs(l - r) > 1) {
            isB = false;
        }
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool isB = true;
        helper(root, isB);
        return isB;
    }
};