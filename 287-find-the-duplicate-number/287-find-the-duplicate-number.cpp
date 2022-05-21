class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums[0];
        for (int i=1;i<nums.size();++i){
            if (nums[i]==n) return n;
            n=nums[i];
        }
        return n;
    }
};