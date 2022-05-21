class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, tmp = 0;
        for (int i=0;i<(int)s.size();++i){
            if (s[i]==' '){
                if (tmp)
                    ans = tmp;
                tmp = 0;
                continue;
            }
            ++tmp;
        }
        if (tmp)
            ans = tmp;
        return ans;
    }
};