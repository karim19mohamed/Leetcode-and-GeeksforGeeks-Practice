class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pt = nums.size() - 1;
        int new_sz = nums.size();
        for (int i=nums.size() - 1;i>=0;--i){
            if (nums[i]==val){
                while(pt!=i && nums[pt]==val){
                    --pt;
                }
                swap(nums[i],nums[pt]);
                --new_sz;
            }
        }
        return new_sz;
    }
};