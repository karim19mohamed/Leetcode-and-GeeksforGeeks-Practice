class Solution {
    bool check_palindrome(string s){
        int n = s.size();
        for(int i=0;i<n/2;++i){
            if (s[i]!=s[n-1-i])
                return false;
        }
        return true;
    }
public:
    int removePalindromeSub(string s) {
        if (check_palindrome(s)){
            return 1;
        }
        return 2;
    }
};

// abaabba
// aaabbbbabbab