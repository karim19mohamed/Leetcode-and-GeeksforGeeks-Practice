class Solution {
    int dp[1001];
    int rec(vector<int>& nums, int rem){
        if (rem==0)
            return 1;
        if (rem<0)
            return 0;
        int &ret = dp[rem];
        if (~ret)
            return ret;
        ret = 0;
        for (auto& num:nums)
            ret += rec(nums, rem-num);
        return ret;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return rec(nums, target);
    }
};