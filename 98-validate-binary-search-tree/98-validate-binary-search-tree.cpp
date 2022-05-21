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
    bool rec(TreeNode* root, TreeNode* min_val, TreeNode* max_val){
        if (root == nullptr)
            return true;
        if ((min_val != nullptr && root->val <= min_val->val)
            || (max_val != nullptr && root->val >= max_val->val))
            return false;
        bool ans = rec(root->left, min_val, root);
        ans &= rec(root->right, root, max_val);
        return ans;
    }
public:
    bool isValidBST(TreeNode* root) {
        bool ans = rec(root, nullptr, nullptr) ;
        return ans;
    }
};