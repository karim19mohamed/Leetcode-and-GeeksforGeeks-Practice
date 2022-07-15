class Solution {
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int sx = 0, sy = 0;
    int dfs(vector<vector<int>>& grid, int curx, int cury){
        int ret = 1;
        grid[curx][cury] = 2;
        for (int i=0;i<4;++i){
            int new_curx = curx + dx[i],
                new_cury = cury + dy[i];
            if (new_curx>=0 && new_curx<sx && new_cury>=0 && new_cury<sy && grid[new_curx][new_cury] == 1){
                // cout << new_curx << "  " << new_cury << endl;
                ret += dfs(grid, new_curx, new_cury);
            }
        }
        return ret;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        sx = grid.size();
        sy = grid[0].size();
        int ans = 0;
        for (int i=0;i<sx;++i){
            for (int j=0;j<sy;++j){
                if (grid[i][j]==1)
                    ans = max(ans,dfs(grid,i,j));
            }
        }
        return ans;
    }
};