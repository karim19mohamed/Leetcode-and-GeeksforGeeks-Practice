class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = false;
        if (nums.size()>1 && nums[1]<nums[0]){
            nums[0] = -1e6;
            flag = true;
        }
        for (int i=2;i<nums.size();++i){
            if (nums[i]<nums[i-1]){
                if (!flag){
                    if (nums[i-2]<=nums[i]){
                        nums[i-1] = nums[i-2];
                    }else{
                        nums[i] = nums[i-1];
                    }
                    flag = true;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};