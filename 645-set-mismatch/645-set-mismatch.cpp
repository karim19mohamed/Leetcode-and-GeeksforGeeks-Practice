class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int missing = 1;
        for (int i=0;i<int(nums.size());++i){
            if (nums[i]==missing){
                ++missing;
            }
            if (i+1<int(nums.size()) && nums[i]==nums[i+1]){
                ans.push_back(nums[i]);
            }
        }
        ans.push_back(missing);
        return ans;
    }
};