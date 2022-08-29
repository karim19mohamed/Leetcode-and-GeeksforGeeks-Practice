class Solution {
    int diag[101];
    void sorter(vector<vector<int>>& mat, int x, int y){
        int sz = 0;
        int n = mat.size(),
            m = mat[0].size();
        int i = x, j = y;
        while(i<n && j<m)
            diag[sz++] = mat[i++][j++];
        sort(diag, diag+sz);
        i = 0;
        while(x<n && y<m)
            mat[x++][y++] = diag[i++];
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(),
            m = mat[0].size();
        for (int i=0;i<n;++i)
            sorter(mat, i, 0);
        for (int i=1;i<m;++i)
            sorter(mat, 0, i);
        return mat;
    }
};