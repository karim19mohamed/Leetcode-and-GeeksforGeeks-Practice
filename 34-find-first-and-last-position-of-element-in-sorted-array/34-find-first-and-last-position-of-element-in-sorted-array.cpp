class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> searchRange;
        int st1 = 0, en1 = nums.size()-1;
        while(st1<en1){
            int mid = st1 + (en1-st1)/2;
            (nums[mid]>=target)? en1 = mid : st1 = mid+1;
        }
        int st2 = 0, en2 = nums.size()-1;
        while(st2<en2){
            int mid = st2 + (en2-st2+1)/2;
            (nums[mid]<=target)? st2 = mid : en2 = mid-1;
        }
        if (nums.size() && nums[st1]==target){
            searchRange.push_back(st1);
            searchRange.push_back(en2);
        }else{
            searchRange.push_back(-1);
            searchRange.push_back(-1);
        }
        return searchRange;
    }
};