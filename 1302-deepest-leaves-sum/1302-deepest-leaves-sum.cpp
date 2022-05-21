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
    int mx_lvl;
    int sum_leaves_per_lvl[109];
    void rec(TreeNode* root,int lvl){
        if (root == NULL)
            return ;
        if (root->left == NULL && root->right == NULL){
            mx_lvl = max(mx_lvl,lvl);
            sum_leaves_per_lvl[lvl] += root->val;
            return ;
        }
        rec(root->left,lvl+1);
        rec(root->right,lvl+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        memset(sum_leaves_per_lvl,0,sizeof(sum_leaves_per_lvl));
        rec(root,0);
        int ans = sum_leaves_per_lvl[mx_lvl];
        return ans;
    }
};