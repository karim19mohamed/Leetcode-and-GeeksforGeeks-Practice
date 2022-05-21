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
    bool rec(TreeNode* p, TreeNode* q){
        if (p==nullptr && q==nullptr)
            return 1;
        if (p==nullptr || q==nullptr)
            return 0;
        if (p->val != q->val)
            return 0;
        bool res = rec(p->left,q->left) & rec(p->right,q->right);
        return res;
    }
    bool iter(TreeNode* p, TreeNode* q){
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* tmp1 = q1.front();
            TreeNode* tmp2 = q2.front();
            q1.pop();
            q2.pop();
            if(tmp1==nullptr && tmp2==nullptr)
                continue;
            if(tmp1==nullptr || tmp2==nullptr)
                return 0;
            if(tmp1->val!=tmp2->val)
                return 0;
            q1.push(tmp1->left);
            q1.push(tmp1->right);
            q2.push(tmp2->left);
            q2.push(tmp2->right);
        }
        return 1;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // return rec(p, q);
        return iter(p, q);
    }
};