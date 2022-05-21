class Solution {
private:
//     void displace(vector<int>& nums, int st, int nxt_idx, int en){
        
//     }
public:
    int removeDuplicates(vector<int>& nums) {
        int pt1 = 0;
        for (int i=1;i<(int)nums.size();++i){
            if (nums[pt1]!=nums[i]){
                nums[++pt1] = nums[i];
            }
        }
        return pt1+1;
    }
};