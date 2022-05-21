class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3];
        cnt[0]=cnt[1]=cnt[2]=0;
        for (int i=0;i<nums.size();++i) ++cnt[nums[i]];
        int idx=0;
        while (cnt[0]) nums[idx++]=0,--cnt[0];
        while (cnt[1]) nums[idx++]=1,--cnt[1];
        while (cnt[2]) nums[idx++]=2,--cnt[2];
    }
};