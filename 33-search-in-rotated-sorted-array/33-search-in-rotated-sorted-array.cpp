class Solution {
    int get_k(vector<int>& nums){
        int st = 0, en = nums.size()-1;
        while(st<en){
            int mid = st + (en-st+1)/2;
            (nums[mid]>=nums[0])? st = mid: en=mid-1;
        }
        cout << st << endl;
        return nums.size() - 1 - st;
    }
public:
    int search(vector<int>& nums, int target) {
        int k = get_k(nums);
        cout << k << endl;
        int beg = (k)? nums.size()- k:0;
        cout << beg << endl;
        int st = 0, en = nums.size()-1;
        while(st<en){
            int mid = st + (en-st+1)/2;
            int idx = (mid<k)? beg+mid : mid-k;
            (nums[idx]<=target)? st = mid: en=mid-1;
        }
        int idx = (st<k)? beg+st : st-k;
        return (nums[idx]==target)? idx : -1;
    }
};