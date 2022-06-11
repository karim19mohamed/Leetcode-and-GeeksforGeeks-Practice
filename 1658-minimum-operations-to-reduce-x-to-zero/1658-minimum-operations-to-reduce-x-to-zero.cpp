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
    int binary_search(vector<int>& prefix_sum, int x, int en){
        // TTTTTTTTTTTTFFFFF
        int st = 0;
        while(st<en){
            int mid = st + (en-st+1)/2;
            (prefix_sum[mid]<=x)? st = mid: en = mid-1;
        }
        return st;
    }
    // int two_pointer_binarysearch(vector<int>& nums, int x){
    //     int sz = nums.size();
    //     vector<int> prefix_sum(sz,0);
    //     prefix_sum[0] = nums[0];
    //     for(int i=1;i<sz;++i){
    //         prefix_sum[i] = nums[i] + prefix_sum[i-1];
    //     }
    //     int res = 1e9;
    //     int sum = 0;
    //     int idx = binary_search(prefix_sum, x-sum, sz-1);
    //     if (prefix_sum[idx]+sum==x){
    //         res = min(res, idx+1);
    //     }
    //     for (int i=nums.size()-1;i>=0;--i){
    //         int sum += nums[i];
    //         int idx = binary_search(prefix_sum, x-sum, i-1);
    //         if (prefix_sum[idx]+sum==x){
    //             res = min(res, idx+1);
    //         }
    //     }
    // }
    int two_pointer(vector<int>& nums, int x){
        int sz = nums.size();
        int pt1 = 0;
        int res = 1e9;
        int sum = 0;
        while(sum<x && pt1!=sz){
            sum += nums[pt1++];
        }
        if (sum == x){
            res = pt1;
        }
        if (sum<x){
            return -1;
        }
        for (int i=sz-1;i>=0;--i){
            sum += nums[i];
            while(sum > x && pt1>0){
                sum -= nums[--pt1];
            }
            if (sum == x){
                res = min(res, (pt1)+(sz-i));
            }
        }
        return (res==1e9)? -1 : res;
    }
public:
    int minOperations(vector<int>& nums, int x) {
        // return naive(nums, x, 0, nums.size()-1);
        return two_pointer(nums, x);
    }
};