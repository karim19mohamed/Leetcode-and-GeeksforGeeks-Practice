class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st = 0, en = nums.size()-1;
        int sz = en;
        while(st<en){
            int mid = st + (en-st)/2;  
            (mid==sz || nums[mid]-nums[mid+1]>=0)? en=mid : st = mid+1;
        }
        return st;
    }
};