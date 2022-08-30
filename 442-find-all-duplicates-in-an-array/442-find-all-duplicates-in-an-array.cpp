class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (auto num : nums){
            int idx = abs(num) - 1;
            if (nums[idx]<0)
                ans.push_back(abs(num));
            nums[idx] = - nums[idx];
        }
        return ans;
    }
};