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
    bool ans = true;
    int rec(TreeNode* root){
        if (root == nullptr)
            return 0;
        int left_res = 1 + rec(root->left);
        int right_res = 1 + rec(root->right);
        if (abs(left_res-right_res)>1)
            ans = false;
        return max(left_res, right_res);
    }
public:
    bool isBalanced(TreeNode* root) {
        ans = true;
        int tmp = rec(root);
        return ans;
    }
};