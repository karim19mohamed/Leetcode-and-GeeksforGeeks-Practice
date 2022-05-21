class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (int i=0;i< (int)(nums.size())-2 ;i+=3){
            for(int j=i+1;j<i+3 && j<nums.size();++j){
                if (nums[i]!=nums[j]) return nums[i];
            }
        }
        return nums.back();
    }
};