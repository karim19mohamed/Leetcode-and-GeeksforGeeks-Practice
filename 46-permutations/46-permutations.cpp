class Solution {
    vector<int> single_per;
    vector<bool>  vis;
    void rec(vector<vector<int>> &res, vector<int>& nums, int sz){
        if (sz<0){
            res.push_back(single_per);
            return;
        }
        for (int i=0;i<nums.size();++i){
            if (!vis[i]){
                single_per[sz] = nums[i];
                vis[i] = 1;
                rec(res, nums, sz-1);
                vis[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        single_per.resize(nums.size(),0);
        vis.resize(nums.size(),0);
        vector<vector<int>> res;
        rec(res, nums, nums.size()-1);
        return res;
    }
};