class Solution {
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int sx = 0, sy = 0;
    void dfs(vector<vector<char>>& grid, int curx, int cury){
        grid[curx][cury] =  '2';
        for (int i=0;i<4;++i){
            int new_curx = curx + dx[i],
                new_cury = cury + dy[i];
            if (new_curx>=0 && new_curx<sx && new_cury>=0 && new_cury<sy && grid[new_curx][new_cury] == '1'){
                dfs(grid, new_curx, new_cury);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        sx = grid.size();
        sy = grid[0].size();
        int ans = 0;
        for (int i=0;i<sx;++i){
            for (int j=0;j<sy;++j){
                if (grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};