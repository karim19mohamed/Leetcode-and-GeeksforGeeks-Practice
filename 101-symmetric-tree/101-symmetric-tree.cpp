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
    bool solver(TreeNode* root1, TreeNode* root2){
        if (root1==nullptr && root2==nullptr)
            return true;
        if (root1==nullptr || root2==nullptr)
            return false;
        bool res = (root1->val==root2->val);
        res &= solver(root1->left, root2->right);
        res &= solver(root1->right, root2->left);
        return res;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solver(root,root);
    }
};