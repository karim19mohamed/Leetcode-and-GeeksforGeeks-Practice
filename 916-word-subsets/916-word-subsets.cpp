class Solution {
    int cnt[26];
    void set_cnt(vector<string>& words2){
        memset(cnt,0,sizeof(cnt));
        int tmp[26];
        for (auto word: words2){
            memset(tmp,0,sizeof(tmp));
            for (auto c : word){
                int num = c-'a';
                ++tmp[num];
                cnt[num] = max(cnt[num],tmp[num]);
            }
        }
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        set_cnt(words2);
        int tmp[26];
        for (auto word: words1){
            memset(tmp,0,sizeof(tmp));
            bool flag = true;
            for (auto c : word){
                int num = c-'a';
                ++tmp[num];
            }
            for (int i=0;i<26;++i){
                if (cnt[i]>tmp[i]){
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(word);
        }
        return ans;
    }
};