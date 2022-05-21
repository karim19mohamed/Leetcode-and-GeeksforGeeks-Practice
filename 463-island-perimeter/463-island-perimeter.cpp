class Solution {
private:
    int i_m[4]={ 0, 0, 1,-1};
    int j_m[4]={ 1,-1, 0, 0};
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0, n=grid.size(), m=grid[0].size();
        for (int i=0;i<n;++i){
            for (int j=0;j<grid[0].size();++j){
                if (grid[i][j]){
                    for (int k=0;k<4;++k){
                        int i_n=i+i_m[k] , j_n=j+j_m[k];
                        if (i_n<0 || i_n>=n || j_n<0 || j_n>=m || !grid[i_n][j_n])
                            ++ans;
                    }
                }
            }
        }
        return ans;
    }
};