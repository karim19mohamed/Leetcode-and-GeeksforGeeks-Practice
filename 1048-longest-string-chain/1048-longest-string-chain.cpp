class Solution {
    bool is_predecessor(string word1, string word2){
        int pt1 = 0, pt2=0;
        int sz1 = word1.size(), sz2 = word2.size();
        if (sz2-sz1!=1)
            return false;
        bool flag = false;
        while(pt1<sz1){
            if (word1[pt1]==word2[pt2]){
                ++pt1;
                ++pt2;
            }else{
                ++pt2;
                if (!flag){
                    flag = true;
                }else{
                    return false;
                }
            }
        }
        if (pt2!=sz2 && !flag){
            flag = true;
            ++pt2;
        }
        return flag && (pt2==sz2);
    }
    bool vis[1001];
    vector<int> adj[1001];
    int dp[1001];
    int dfs(int idx){
        if (vis[idx]){
            return 0;
        }
        int& res = dp[idx];
        if (~res)
            return res;
        res = 1;
        for (auto v:adj[idx]){
            vis[idx] = 1;
            res = max(res, 1 + dfs(v));
            vis[idx] = 0;
        }
        return res;
    }
    void init(int sz){
        memset(vis,0, sz * sizeof(vis[0]));
        memset(dp, -1, sz * sizeof(dp[0]));
        for (int i=0;i<sz;++i){
             adj[i].clear();
        }
    }
public:
    int longestStrChain(vector<string>& words) {
        int sz = words.size();
        init(sz);
        for (int i=0;i<sz;++i){
            for (int j=i+1;j<sz;++j){
                if (abs( ((int)words[i].size()) - ((int)words[j].size()) )!=1)
                    continue;
                string word1 = words[i],
                       word2 = words[j];
                int idx1 = i,
                    idx2 = j;
                if (word2.size()<word1.size()){
                    swap(word1,word2);
                    swap(idx1,idx2);
                }
                if (is_predecessor(word1, word2)){
                    adj[idx1].push_back(idx2);
                }
            }
        }
        int ans = 0;
        for (int i=0;i<sz;++i){
            ans = max(ans, dfs(i));
        }
        
        return ans;
    }
};