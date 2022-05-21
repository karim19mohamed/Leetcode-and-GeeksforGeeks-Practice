class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, en = nums.size()-1;
        while(st<en){
            int mid = st + (en-st+1)/2;
            (nums[mid]<=target)? st=mid: en=mid-1;
        }
        return (nums[st]==target)? st : -1;
    }
};