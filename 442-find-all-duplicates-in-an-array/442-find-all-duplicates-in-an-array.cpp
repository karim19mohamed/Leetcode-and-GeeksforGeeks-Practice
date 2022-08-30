class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i=0;i<nums.size();++i){
            int num = nums[i];
            int idx = abs(num) - 1;
            if (nums[idx]<0)
                ans.push_back(idx+1);
            nums[idx] = - nums[idx];
        }
        return ans;
    }
};