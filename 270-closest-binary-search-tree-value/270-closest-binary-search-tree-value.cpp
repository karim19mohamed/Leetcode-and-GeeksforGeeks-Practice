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
    int ans;
    void rec(TreeNode* root, double& target){
        if (root==nullptr)
            return;
        if (abs(target-root->val)<abs(target-ans))
            ans = root->val;
        rec(root->left, target);
        rec(root->right, target);
    }
public:
    int closestValue(TreeNode* root, double target) {
        ans = 1e9 + 1;
        rec(root, target);
        return ans;
    }
};