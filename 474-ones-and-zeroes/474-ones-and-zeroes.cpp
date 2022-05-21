class Solution {
private:
    int data[609][2];
    int dp[609][109][109];
    int rec(int idx,int m,int n){
        if (idx==-1) return 0;
        
        int& ret = dp[idx][m][n];
        if (~ret) return ret;
            
        ret = rec(idx-1,m,n);
        if (data[idx][0]<=m && data[idx][1]<=n)
            ret = max(ret, 1+rec(idx-1, m-data[idx][0], n-data[idx][1]) );
        return ret;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(data,0,sizeof(data));
        memset(dp,-1,sizeof(dp));
        for (int i=0;i<int(strs.size());++i){
            int zeros = 0, ones = 0;
            string cur = strs[i];
            for (int j=0;j<int(cur.size());++j)
                (cur[j]=='0')? ++zeros: ++ones;
            data[i][0] = zeros;
            data[i][1] = ones;
        }
        int ans = rec(int(strs.size())-1,m,n);
        return ans;
    }
};