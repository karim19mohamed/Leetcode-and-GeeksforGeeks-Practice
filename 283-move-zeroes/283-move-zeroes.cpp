class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pt1=0, pt2=0;
        while(pt1<nums.size() && pt2<nums.size()){
            if (nums[pt1]==0 && nums[pt2]==0){
                ++pt2;
            }else if (nums[pt1]==0){
                swap(nums[pt1], nums[pt2]);
                ++pt1;
                ++pt2;
            }else{
                ++pt1;
                ++pt2;
            }
        }
    }
};