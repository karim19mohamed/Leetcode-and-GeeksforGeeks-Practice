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
        if (root == nullptr)
            return 0;
        int res = 1+max(rec(root->left), rec(root->right));
        return res;
    }
public:
    int maxDepth(TreeNode* root) {
        return rec(root);
    }
};