class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int sz = s.size();
        for(int i = 0; i < (s.size())/2; i++){
            if(s[i] != s[sz-1 -i]){
                return false;
            }
        }
        return true;
    }
};