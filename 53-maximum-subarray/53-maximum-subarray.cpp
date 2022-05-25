class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int res = nums[0];
        int pt1 = 0, pt2 = 1;
        while(pt1<pt2 || pt2<nums.size()){
            if (pt1<pt2 && nums[pt1]<=0){
                res -= nums[pt1];
                ++pt1;
            }else if (pt2<nums.size() && res+nums[pt2]>0){
                res += nums[pt2];
                pt2++;
            }else if (pt1<pt2){
                res -= nums[pt1];
                ++pt1;
            }else {
                res += nums[pt2];
                pt2++;
            }
            if (pt1<pt2)
                ans = max(ans, res);
        }
        return ans;
    }
};