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
    void rec(int n, vector<string> board, vector<vector<string>> &ans){
        if (n==0){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<N;++j){
            if (!row[n-1] && !col[j] && !dig_r[n-1+j] && !dig_l[n-1-j+offset]){
                board[n-1][j] = 'Q';
                row[n-1] = col[j] = dig_r[n-1+j] = dig_l[n-1-j+offset] = true;

                rec(n-1, board, ans);

                board[n-1][j] = '.';
                row[n-1] = col[j] = dig_r[n-1+j] = dig_l[n-1-j+offset] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n,'.');
        for(int i=0;i<n;++i)
            board.push_back(s);
        init(n);
        
        rec(n, board, ans);
        
        return ans;
    }
};