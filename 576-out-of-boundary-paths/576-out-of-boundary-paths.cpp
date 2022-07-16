class Solution {
    int M = 0, N = 0, MOD = 1e9 + 7;
    int dx[4] = {0,1,-1,0};
    int dy[4] = {1,0,0,-1};
    int dp[51][51][51];
    int rec(int maxMove, int startRow, int startColumn){
        if (startRow<0 || startRow>=M || startColumn<0 || startColumn>=N)
            return 1;
        if (!maxMove)
            return 0;
        int& res = dp[startRow][startColumn][maxMove];
        if (~res)
            return res;
        res = 0;
        for (int i=0;i<4;++i){
            int new_row = startRow + dx[i],
                new_col = startColumn + dy[i];
            res = (res + ( rec(maxMove-1, new_row, new_col) % MOD ) ) % MOD;
        }
        return res;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M = m;
        N = n;
        memset(dp, -1, sizeof(dp));
        return rec(maxMove, startRow, startColumn);
    }
};