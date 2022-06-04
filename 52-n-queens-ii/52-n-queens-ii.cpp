class Solution {
    bool row[10], col[10], dig_r[19], dig_l[19];
    const int offset = 9;
    int N;
    void init(int n){
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(dig_r,0,sizeof(dig_r));
        memset(dig_l,0,sizeof(dig_l));
        N = n;
    }
    void rec(int n, int &ans){
        if (n==0){
            ++ans;
            return;
        }
        for(int j=0;j<N;++j){
            if (!row[n-1] && !col[j] && !dig_r[n-1+j] && !dig_l[n-1-j+offset]){
                row[n-1] = col[j] = dig_r[n-1+j] = dig_l[n-1-j+offset] = true;
                rec(n-1, ans);
                row[n-1] = col[j] = dig_r[n-1+j] = dig_l[n-1-j+offset] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        int ans = 0;
        init(n);
        
        rec(n, ans);
        
        return ans;
    }
};