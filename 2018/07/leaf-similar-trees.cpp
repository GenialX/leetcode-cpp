#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            vector<int> v1, v2;
            v1 = getLeaf(root1);
            v2 = getLeaf(root2);
            for (unsigned long i = 0; i < v1.size(); i++) {
                cout<<v1[i]<<endl;
                cout<<v2[i]<<endl;
            }
            return true;
        }

        vector<int> getLeaf(TreeNode* root) {
            stack<TreeNode*> s;
            vector<int> v;
            TreeNode* cur;
            if (root->left == NULL && root->right == NULL) {
                v.push_back(root->val);
                return v;
            }
            s.push(root);
            while (!s.empty() && (cur = s.top())) {
                if (cur->left != NULL) {
                    s.push(cur->left);
                    cout<<"s push "<<cur->left->val<<endl;
                    if (cur->left->left == NULL && cur->left->right == NULL) {
                        v.push_back(cur->left->val);
                    }
                    cur->left = NULL;
                    continue;
                }
                if (cur->right != NULL) {
                    s.push(cur->right);
                    cout<<"s push "<<cur->right->val<<endl;
                    if (cur->right->left == NULL && cur->right->right == NULL) {
                        v.push_back(cur->right->val);
                    }
                    cur->right = NULL;
                    continue;
                }
                cout<<"s pop "<<cur->val<<endl;
                s.pop();
            }
            cout<<"retun"<<endl;
            return v;
        }
};

int main(int argc, char * argv[]) {

    Solution * s = new Solution();
    TreeNode *l1;
    l1 = new TreeNode(1);
    l1->left = new TreeNode(2);
    l1->right = new TreeNode(3);
    
    l1->left->left = new TreeNode(4);
    l1->left->right = new TreeNode(5);


    l1->right->left = new TreeNode(6);


    bool r = s->leafSimilar(l1, l1);
}
