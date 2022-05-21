class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (int i=0;i<(int)nums.size()-1;++i){
            bool flag = true;
            while (nums[i]==nums[i+1]){
                ++i;
                flag =false;
            }
            if (flag)
                return nums[i];
        }
        return nums.back();
    }
};