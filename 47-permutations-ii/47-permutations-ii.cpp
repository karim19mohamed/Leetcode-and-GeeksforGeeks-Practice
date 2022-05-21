class Solution {
    bool vis[10];
    vector<int> tmp;
    map<vector<int>, int> m;
    int vid = 0;
    void rec(vector<vector<int>> &res, vector<int>& nums, int sz){
        if (sz<0){
            if (m[tmp] != vid){
                res.push_back(tmp);
                m[tmp] = vid;
            }
            return;
        }
        for (int i=0;i<(int)nums.size();++i){
            if (!vis[i]){
                vis[i] = 1;
                tmp[sz] = nums[i];
                rec(res, nums, sz-1);
                vis[i] = 0;
            }
        }
        
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ++vid;
        memset(vis,0,sizeof(vis));
        vector<vector<int>> res;
        vector<int> tmp2(nums.size(), 0);
        tmp = tmp2;
        rec(res, nums, nums.size()-1);
        return res;
    }
};