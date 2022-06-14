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
public:
    int minDistance(string word1, string word2) {
        sz1 = word1.size();
        sz2 = word2.size();
        
        // naive recursion
        // return naive(word1, word2, 0, 0);
        
        // recursive dp
        memset(dp,-1,sizeof(dp));
        return dp_rec(word1, word2, 0, 0);
    }
};