class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[30];
        memset(cnt,0,sizeof(cnt));
        for (auto c:s)
            cnt[c-'a']++;
        for (auto c:t){
            cnt[c-'a']--;
            if(cnt[c-'a']<0)
                return false;
        }
        return s.size()==t.size();
    }
};