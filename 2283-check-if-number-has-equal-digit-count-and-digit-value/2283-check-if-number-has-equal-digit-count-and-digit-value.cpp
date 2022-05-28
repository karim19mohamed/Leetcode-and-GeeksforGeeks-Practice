class Solution {
public:
    bool digitCount(string num) {
        int a[10];
        memset(a,0,sizeof(a));
        for(auto c:num){
            a[c-'0']++;
        }
        for(int i=0;i<num.size();++i){
            if (a[i]!=num[i]-'0')
                return false;
        }
        return true;
    }
};