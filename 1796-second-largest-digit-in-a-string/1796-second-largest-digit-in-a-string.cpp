class Solution {
private:
    bool a[10];
public:
    int secondHighest(string s) {
        memset(a,0,sizeof(a));
        int ans = -1;
        for (int i=0;i<int(s.size());++i){
            if(s[i]>='0' && s[i]<='9')
                a[s[i]-'0']=1;
        }
        int cnt = 0;
        for (int i=9;i>=0;--i){
            if(a[i]) ++cnt;
            if(cnt==2){
                ans =i;
                break;
            }
        }
        return ans;
    }
};