class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, en = nums.size()-1;
        while(st<en){
            int mid = st + (en-st)/2;
            (nums[mid]<nums[0])? en = mid : st = mid+1;
            // cout << st << "  " << en << endl;
        }
        // cout << st << endl;
        return (nums[st]<nums[0])? nums[st] : nums[0];
    }
};