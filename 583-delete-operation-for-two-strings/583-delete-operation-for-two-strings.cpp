class Solution {
    int sz1 = 0, sz2 = 0;
    int naive(string word1, string word2, int idx1, int idx2){
        if (idx1==sz1 || idx2==sz2){
            return sz1-idx1 + sz2-idx2;
        }
        int res = 0;
        if (word1[idx1]==word2[idx2]){
            res += naive(word1, word2, idx1+1, idx2+1);
        }else{
            res += 1 + min(naive(word1, word2, idx1+1, idx2),
                           naive(word1, word2, idx1, idx2+1));
        }
        return res;
    }
    int dp[509][501];
    int dp_rec(string word1, string word2, int idx1, int idx2){
        if (idx1==sz1 || idx2==sz2){
            return sz1-idx1 + sz2-idx2;
        }
        int& res = dp[idx1][idx2];
        if (~res)
            return res;
        if (word1[idx1]==word2[idx2]){
            res = dp_rec(word1, word2, idx1+1, idx2+1);
        }else{
            res = 1 + min(dp_rec(word1, word2, idx1+1, idx2),
                          dp_rec(word1, word2, idx1, idx2+1));
        }
        return res;
    }
    int dp_iter(string word1, string word2){
        for (int i=0;i<sz1;++i){
            dp[i][sz2] = sz1-i;
        }
        for (int i=0;i<sz2;++i){
            dp[sz1][i] = sz2-i;
        }
        dp[sz1][sz2] = 0;
        for (int idx1=sz1-1; idx1>-1; --idx1){
            for (int idx2=sz2-1; idx2>-1; --idx2){
                if (word1[idx1]==word2[idx2]){
                    dp[idx1][idx2] = dp[idx1+1][idx2+1];
                }else{
                    dp[idx1][idx2] = 1 + min(dp[idx1+1][idx2],
                                             dp[idx1][idx2+1]);
                }
            }
        }
        return dp[0][0];
    }
public:
    int minDistance(string word1, string word2) {
        sz1 = word1.size();
        sz2 = word2.size();
        
        // naive recursion
        // return naive(word1, word2, 0, 0);
        
        // recursive dp
        // memset(dp,-1,sizeof(dp));
        // return dp_rec(word1, word2, 0, 0);
        
        // iterative dp
        memset(dp,-1,sizeof(dp));
        return dp_iter(word1, word2);
    }
};