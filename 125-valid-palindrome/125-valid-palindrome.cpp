class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> v;
        for (int i=0;i<(int)s.size();++i){
            if (s[i]>=97 && s[i]<=122)
                v.push_back(s[i]);
            if (s[i]>=65 && s[i]<=90)
                v.push_back(s[i]+32);
            if (s[i]>='0' && s[i]<='9')
                v.push_back(s[i]);
        }
        int ans = true;
        int n = (int)v.size();
        for (int i=0;i<n/2;++i){
            if (v[i]!=v[n-1-i]){
                ans = false;
                break;
            }  
        }
        return ans;
    }
};