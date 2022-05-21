class Solution {
private:
    char c[7] = {'I','V','X','L','C','D','M'};
    int n[7] = {1,5,10,50,100,500,1000};
    bool rule(string s, int sz, int &i ,int &ans){
        int old_ans = ans;
        if (i+1<sz){
            if (s[i]=='I'){
                if (s[i+1]=='V')
                    ans += 4;
                if (s[i+1]=='X')
                    ans += 9;
            }
            if (s[i]=='X'){
                if (s[i+1]=='L')
                    ans += 40;
                if (s[i+1]=='C')
                    ans += 90;
            }
            if (s[i]=='C'){
                if (s[i+1]=='D')
                    ans += 400;
                if (s[i+1]=='M')
                    ans += 900;
            }
        }
        return old_ans<ans;
    }
public:
    int romanToInt(string s) {
        int ans = 0;
        int sz = (int)s.size();
        for (int i=0;i<sz;++i)
            for (int j=0;j<7;++j)
                if (c[j]==s[i]){
                    if (rule(s, sz, i, ans)){
                        ++i;
                        break;
                    }
                    ans += n[j];
                    break;
                }
        return ans;
    }
};