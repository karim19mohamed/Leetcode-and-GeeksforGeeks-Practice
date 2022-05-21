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
private:
    int rec(TreeNode* root){
        if (root!=nullptr && root->left==nullptr && root->right==nullptr)
            return 1;
        if (root==nullptr)
            return INT_MAX;
        int res = 1 + min(rec(root->left),rec(root->right));
        return res;
    }
public:
    int minDepth(TreeNode* root) {
        return (root==nullptr)? 0:rec(root);
    }
};