class Solution {
    int dp[1001];
    int rec(vector<int>& cost, int idx){
        if (idx>=cost.size()){
            return 0;
        }
        int& res = dp[idx];
        if (~res)
            return res;
        res = cost[idx] + min(rec(cost, idx+1), rec(cost, idx+2));
        return res;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        memset(dp,-1,sz*sizeof(cost[0]));
        return min(rec(cost,0), rec(cost,1));
    }
};