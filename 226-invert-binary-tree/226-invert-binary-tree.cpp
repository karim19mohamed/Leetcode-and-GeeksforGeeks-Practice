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
public:
    void invertT(TreeNode* root){
        if (root==NULL) return;
        invertT(root->right);
        invertT(root->left);
        swap(root->right,root->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        invertT(root);
        return root;
    }
};