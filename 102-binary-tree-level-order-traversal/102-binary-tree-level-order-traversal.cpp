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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        vector<int> tmp;
        ans.push_back(tmp);
        ans[0].push_back(root->val);
        
        queue<TreeNode* > q;
        q.push(root);
        int level = 1;
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                TreeNode* parent = q.front();
                q.pop();
                if (parent->left != nullptr){
                    q.push(parent->left);
                    if (level > ans.size()-1){
                        vector<int> tmp;
                        ans.push_back(tmp);
                    }
                    ans[level].push_back(parent->left->val);
                    // cout << parent->left->val << endl;
                }
                if (parent->right != nullptr){
                    q.push(parent->right);
                    if (level > ans.size()-1){
                        vector<int> tmp;
                        ans.push_back(tmp);
                    }
                    ans[level].push_back(parent->right->val);
                    // cout << parent->right->val << endl;
                }
            }
            ++level;
        }
        
        return ans;
    }
};