class Solution {
    int N = 1e4 + 1;
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        bool cnt[N];
        memset(cnt,0,sizeof(cnt));
        int pt1 = 0, pt2 = 0, sum = 0, ans = 0;
        while(pt2<nums.size()){
            int num2 = nums[pt2],
                num1 = nums[pt1];
            if (!cnt[num2]){
                sum += num2;
                cnt[num2] = true;
                ++pt2;
            }else{
                sum -= num1;
                cnt[num1] = false;
                ++pt1;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};