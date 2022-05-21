class Solution {
    void rec(vector<char>& s, int idx){
        if (idx==s.size()/2)
            return;
        swap(s[idx],s[s.size()-1-idx]);
        rec(s,idx+1);
    }
public:
    void reverseString(vector<char>& s) {
        rec(s, 0);
    }
};