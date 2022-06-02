class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> trans;
        for (int i=0;i<m;++i){
            vector<int> tmp(n,0);
            trans.push_back(tmp);
        }
        for (int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                trans[j][i] = matrix[i][j];
            }
        }
        return trans;
    }
};