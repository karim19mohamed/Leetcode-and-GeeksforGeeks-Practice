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
    // bool camera[1001];
    int dp[1001][3];
    int dfs(TreeNode* root, int vision){
        if (root==nullptr)
            return 0;
        int& res = dp[root->val][vision];
        if (~ res)
            return res;
            
        res = 1e5;
        res = min(res, 1 + dfs(root->right, 2) + dfs(root->left, 2) );
        if (vision == 1){
            if (root->right != nullptr){
                res = min(res, dfs(root->right, vision-1) + dfs(root->left, vision) );
            }
            if (root->left != nullptr){
                res = min(res, dfs(root->right, vision) + dfs(root->left, vision-1) );
            }
        }else if (vision == 2){
            res = min(res, dfs(root->right, vision-1) + dfs(root->left, vision-1) );
        }
        return res;
    }
    void define_id (TreeNode* root, bool flag){
        int id = 0;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            node->val = (flag)? id++ : 0;
            if (node->right != nullptr)
                st.push(node->right);
            if (node->left != nullptr)
                st.push(node->left);
        }
    }
public:
    int minCameraCover(TreeNode* root) {
        memset(dp, -1, sizeof(dp));
        define_id (root, true);
        int ans = dfs(root, 1);
        define_id (root, false);
        return ans;
        
    }
};