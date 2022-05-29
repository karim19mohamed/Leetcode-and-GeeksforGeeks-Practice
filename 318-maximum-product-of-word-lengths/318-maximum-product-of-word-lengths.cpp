class Solution {
    void set_array(bool a[], string s){
        for (auto c:s)
            a[c-'a'] = 1;
    }
    bool has_common(bool a[], string s){
        for (auto c:s){
            if (a[c-'a'])
                return true;
        }
        return false;
    }
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        for (int i=0;i<words.size();++i){
            bool a[30];
            memset(a,0,sizeof(a));
            set_array(a, words[i]);
            for (int j=i+1;j<words.size();++j){
                if (!has_common(a, words[j])){
                    int tmp = words[i].size()*words[j].size();
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};