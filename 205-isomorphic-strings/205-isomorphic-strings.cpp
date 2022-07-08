class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int replacement[130];
        bool taken[130];
        memset(replacement,0,sizeof(replacement));
        memset(taken,0,sizeof(taken));
        int sz = s.size();
        for (int i=0;i<sz;++i){
            int cur = s[i];
            if (replacement[cur] == 0){
                if (!taken[t[i]]){
                    replacement[cur] = t[i];
                    taken[t[i]] = 1;
                }else{
                    return false;
                }
            }else{
                char rep = replacement[cur];
                if (rep != t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};