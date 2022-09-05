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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        int sz = 1;
        while(!q.empty()){
            double tmp = 0.0;
            for(int i=0;i<sz;++i){
                TreeNode* cur = q.front();
                q.pop();
                tmp += (cur->val*1.0);
                if (cur->left!=nullptr)
                    q.push(cur->left);
                if (cur->right!=nullptr)
                    q.push(cur->right);
            }
            tmp /= (sz*1.0);
            // cout << tmp << endl;
            ans.push_back(tmp);
            sz = q.size();
        }
        
        return ans;
    }
};