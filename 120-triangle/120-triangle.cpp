class Solution {
    int naive(vector<vector<int>>& triangle, int lvl, int idx){
        if (lvl==triangle.size())
            return 0;
        int res = triangle[lvl][idx] + min(naive(triangle, lvl+1, idx+1),
                                           naive(triangle, lvl+1, idx));
        return res;
    }
    int dp[201][201];
    int dp_rec(vector<vector<int>>& triangle, int lvl, int idx){
        if (lvl==triangle.size())
            return 0;
        int& res = dp[lvl][idx];
        if (~res)
            return res;
        res = triangle[lvl][idx] + min(dp_rec(triangle, lvl+1, idx+1),
                                       dp_rec(triangle, lvl+1, idx));
        return res;
    }
    int dp_iter(vector<vector<int>>& triangle){
        int sz = triangle.size();
        for (int idx = 0; idx<triangle[sz-1].size(); ++idx){
            dp[sz-1][idx] = triangle[sz-1][idx];
        }
        for (int lvl=sz-2; lvl>-1; --lvl){
            for (int idx = 0; idx<triangle[lvl].size(); ++idx){
                dp[lvl][idx] = triangle[lvl][idx] + min(dp[lvl+1][idx+1],
                                                        dp[lvl+1][idx]);
            }
        }
        return dp[0][0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Naive Solution
        // return naive(triangle, 0, 0);
        
        // Recursive DP
        // memset(dp, -1, sizeof(dp));
        // return dp_rec(triangle, 0, 0);
        
        // Iterative DP
        return dp_iter(triangle);
        
    }
};