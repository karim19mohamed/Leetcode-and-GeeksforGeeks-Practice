class Solution {
    int solution(vector<int>& nums){
        int n = nums.size();
        int sum = (n+1)*n/2;
        for (int i=0;i<nums.size();++i)
            sum -= nums[i];
        return sum;
    }
public:
    int missingNumber(vector<int>& nums) {
        return solution(nums);
    }
};