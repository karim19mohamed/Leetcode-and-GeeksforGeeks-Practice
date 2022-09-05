/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root==NULL)
            return ans;
        queue<Node*> q;
        q.push(root);
        int sz = 1;
        while(!q.empty()){
            vector<int> tmp(sz);
            for(int i=0;i<sz;++i){
                Node* cur = q.front();
                q.pop();
                tmp[i] = cur->val;
                for (auto v:cur->children)
                    if (v!=NULL)
                        q.push(v);
            }
            ans.push_back(tmp);
            sz = q.size();
        }
        
        return ans;
    }
};










