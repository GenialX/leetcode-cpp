/**
 * https://leetcode.com/contest/weekly-contest-98/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
 *
 * related topic: tree construction
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
        TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
            int len = post.size();
            // traversing the post
            for (int i = 0; i < len; i++) {
                m[post[i]] = i;
            }
            return construct(pre, post, 0, len - 1, 0, len - 1);
        }

        TreeNode* construct(vector<int>& pre, vector<int>& post, int pre_s, int pre_e, int post_s, int post_e) {
            // boundary conditions
            if (pre_s > pre_e) return nullptr;
            TreeNode* root = new TreeNode(pre[pre_s]);
            if (pre_s == pre_e) return root;

            // get left & right node
            int left_len = m[pre[pre_s + 1]] - post_s + 1;
            root->left = construct(pre, post, pre_s + 1, pre_s + left_len, post_s, post_s + left_len - 1);
            root->right = construct(pre, post, pre_s + left_len + 1, pre_e, post_s + left_len, post_e - 1);

            return root;
        }

    private:
        map<int, int> m;
};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    vector<int> l1, l2;
    l1.push_back(1);
    l1.push_back(2);
    l2.push_back(2);
    l2.push_back(1);
    TreeNode* c = s->constructFromPrePost(l1, l2);
    cout<<c->val<<endl;
}
