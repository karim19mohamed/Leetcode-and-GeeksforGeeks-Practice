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
    vector <vector <int>> ans;
    void dfs(TreeNode* root,int lvl){
        if (root==NULL) return;
        if (lvl>=ans.size()){
            vector <int> tmp;
            ans.push_back(tmp);
        }
        
        ans[lvl].push_back(root->val);
        dfs(root->left,lvl+1);
        dfs(root->right,lvl+1);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(root,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};