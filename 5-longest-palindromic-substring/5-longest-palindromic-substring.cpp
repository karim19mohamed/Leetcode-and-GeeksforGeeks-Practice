class Solution {
    int sz_palindrome(string s, int& st, int& en){
        if (s[st]!=s[en])
            return 0;
        int tmp_st = st, tmp_en = en;
        while(tmp_st>-1 && tmp_en<s.size() && s[tmp_st]==s[tmp_en]){
            st = tmp_st;
            en = tmp_en;
            --tmp_st;
            ++tmp_en;
        }
        return en-st+1;
    }
public:
    string longestPalindrome(string s) {
        int max_sz = 0;
        int ans_st, ans_en;
        for (int i=0;i<s.size();++i){
            int tmp_st = i, tmp_en = i;
            int sz = sz_palindrome(s, tmp_st, tmp_en);
            if (sz>max_sz){
                max_sz = sz;
                ans_st = tmp_st;
                ans_en = tmp_en;
            }
            int j = i+1;
            if (j<s.size()){
                tmp_st = i;
                tmp_en = j;
                sz = sz_palindrome(s, tmp_st, tmp_en);
                if (sz>max_sz){
                    max_sz = sz;
                    ans_st = tmp_st;
                    ans_en = tmp_en;
                }
            }
        }
        return s.substr(ans_st, max_sz);
    }
};