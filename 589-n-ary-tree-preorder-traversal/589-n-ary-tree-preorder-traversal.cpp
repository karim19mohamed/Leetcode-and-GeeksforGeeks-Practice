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
    void rec(Node* root, vector<int> &ans){
        if (!root)
            return;
        ans.push_back(root->val);
        for(auto child: root->children)
            rec(child,ans);
    }
    void iter(Node* root, vector<int> &ans){
        if (!root)
            return;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            int sz = cur->children.size();
            for(int i=sz-1;i>-1;--i){
                Node* child = cur->children[i];
                if (child)
                    st.push(child);
            }
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        // rec(root, ans);
        iter(root, ans);
        return ans;
    }
};











