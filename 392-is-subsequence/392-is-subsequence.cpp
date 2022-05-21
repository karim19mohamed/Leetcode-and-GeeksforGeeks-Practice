class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size()>t.size()) return false;
        if (s.size()==0) return true;
        int idx=0;
        for (int i=0;i<t.size();++i){
            if (idx==s.size()) return true;
            if (s[idx]==t[i]) ++idx;
        }
        return idx==s.size();
    }
};