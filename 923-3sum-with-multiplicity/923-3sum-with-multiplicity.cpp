class Solution {
private:
    int M = 1e9 + 7;
    vector<int> num;
    int dp[3009][309][9];
    int rec(int indx,int target,int it){
        if (target==0 && it==3) return 1;
        if (indx==num.size() || it==3) return 0;
        
        int& ret = dp[indx][target][it];
        if (~ret){
            return ret;
        }
        ret = rec(indx+1,target,it)%M;
        if (target-num[indx]>=0)
            ret = (ret + rec(indx+1,target-num[indx],it+1))%M;
        
        return ret;
    }
public:
    int threeSumMulti(vector<int>& arr, int target) {
        memset(dp,-1,sizeof(dp));
        num = arr;
        int ans = rec(0,target,0);
        return ans;
    }
};