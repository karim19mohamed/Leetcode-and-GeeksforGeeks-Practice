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
    vector <int> leafs;
    void solve(TreeNode* root,int num){
        if (root==NULL) return;
        if (root->left==NULL && root->right==NULL ) leafs.push_back(num*10+root->val);
        
        solve(root->left,num*10+root->val);
        solve(root->right,num*10+root->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        int ans=0;
        for (int i=0;i<leafs.size();++i){
            //cout << leafs[i] << endl;
            ans+=leafs[i];
        }
        return ans;
    }
};