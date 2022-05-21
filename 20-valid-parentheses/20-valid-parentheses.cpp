class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool ans = true;
        for (int i=0;i<(int)s.size();++i){
            char c = s[i];
            if (c==')' || c==']' || c=='}'){
                if (st.empty() ||
                    (st.top()!='(' && c==')') ||
                    (st.top()!='[' && c==']') ||
                    (st.top()!='{' && c=='}') ){
                    ans = false;
                    break;
                }
                st.pop();
            }else{
                st.push(c);
            }
            
        }
        if (!st.empty()){
            ans = false;
        }
        return ans;
    }
};