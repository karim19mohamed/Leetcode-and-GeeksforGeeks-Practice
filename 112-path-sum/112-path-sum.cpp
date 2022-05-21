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
    bool rec(TreeNode* root, int targetSum){
        if (root==nullptr)
            return false;
        if (targetSum-root->val==0 && root->left==nullptr && root->right==nullptr)
            return true;
        bool res = rec(root->left, targetSum-root->val) |
                   rec(root->right, targetSum-root->val);
        return res;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==nullptr)
            return false;
        return rec(root, targetSum);
    }
};