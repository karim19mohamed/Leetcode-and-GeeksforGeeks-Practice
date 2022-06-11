class Solution {
    int naive(vector<int>& nums, int x, int pt1, int pt2){
        if (x<0 || pt1>pt2)
            return 1e9;
        if (x==0)
            return 0;
        int res = 1e9;
        res = min(res, 1 + naive(nums, x-nums[pt1], pt1+1, pt2));
        res = min(res, 1 + naive(nums, x-nums[pt2], pt1, pt2-1));
        return res;
    }
    int two_pointer(vector<int>& nums, int x){
        int sz = nums.size(),
            pt1 = 0,
            res = 1e9,
            sum = 0;
        while(sum<x && pt1!=sz)
            sum += nums[pt1++];
        if (sum == x)
            res = pt1;
        if (sum<x)
            return -1;
        for (int i=sz-1;i>=0;--i){
            sum += nums[i];
            while(sum > x && pt1>0)
                sum -= nums[--pt1];
            if (sum == x)
                res = min(res, (pt1)+(sz-i));
        }
        return (res==1e9)? -1 : res;
    }
public:
    int minOperations(vector<int>& nums, int x) {
        // return naive(nums, x, 0, nums.size()-1);
        return two_pointer(nums, x);
    }
};