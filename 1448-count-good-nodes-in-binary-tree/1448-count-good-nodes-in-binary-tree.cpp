/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int rec(TreeNode* root, int max_val){
        if (root == nullptr)
            return 0;
        int ret = 0;
        if (root->val>=max_val)
            ret = 1 + rec(root->left, root->val)
                    + rec(root->right, root->val);
        else
            ret = rec(root->left, max_val)
                  + rec(root->right, max_val);
        return ret;
    }
public:
    int goodNodes(TreeNode* root) {
        return rec(root, -1e5);
    }
};