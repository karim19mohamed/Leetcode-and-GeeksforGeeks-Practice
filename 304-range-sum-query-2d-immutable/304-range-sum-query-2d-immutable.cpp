class NumMatrix {
    vector<vector<int>> accu_sum;
    int n,m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        for (int i=0;i<n;++i){
            vector<int> tmp(m,0);
            accu_sum.push_back(tmp);
        }
        for (int i=0;i<n;++i){
            int sum = 0;
            for (int j=0;j<m;++j){
                sum += matrix[i][j];
                if (i>0){
                    accu_sum[i][j] += accu_sum[i-1][j];
                }
                accu_sum[i][j] += sum;
                
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = accu_sum[row2][col2];
        int chk = 0;
        if (row1>0){
            res -= accu_sum[row1-1][col2];
            ++chk;
        }
        if (col1>0){
            res -= accu_sum[row2][col1-1];
            ++chk;
        }
        if (chk==2){
            res += accu_sum[row1-1][col1-1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */