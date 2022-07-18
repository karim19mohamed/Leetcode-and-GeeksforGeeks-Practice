class Solution {
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int sx = 0, sy = 0, vid = 0, original_id = 0;
    void dfs(vector<vector<int>>& grid, int curx, int cury){
        grid[curx][cury] =  vid;
        for (int i=0;i<4;++i){
            int new_curx = curx + dx[i],
                new_cury = cury + dy[i];
            if (new_curx>=0 && new_curx<sx && new_cury>=0 && new_cury<sy && grid[new_curx][new_cury] == original_id){
                dfs(grid, new_curx, new_cury);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        sx = image.size();
        sy = image[0].size();
        vid = color;
        original_id = image[sr][sc];
        if (vid != original_id)
            dfs(image, sr, sc);
        return image;
    }
};