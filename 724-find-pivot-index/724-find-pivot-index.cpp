class Solution {
    vector<int> runningSum(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res(sz,0);
        res[0] = nums[0];
        for(int i=1;i<sz;++i){
            res[i] = res[i-1] + nums[i];
        }
        return res;
    }
public:
    int pivotIndex(vector<int>& nums) {
        int sz = nums.size();
        vector<int> prefix_sum = runningSum(nums);
        for (int i=0;i<sz;++i){
            if (prefix_sum[i]-nums[i] == prefix_sum[sz-1]-prefix_sum[i]){
                return i;
            }
        }
        return -1;
    }
};