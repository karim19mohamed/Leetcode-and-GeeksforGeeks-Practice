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
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp, -1, sizeof(dp));
        return dp_rec(triangle, 0, 0);
        // return naive(triangle, 0, 0);
    }
};