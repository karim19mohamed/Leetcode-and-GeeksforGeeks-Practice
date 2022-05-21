class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans((int)nums.size());
        int pt1 = (int)nums.size() - 1, pt2 = 0, pt = (int)nums.size()-1;
        while(pt1>=pt2){
            int n1 = nums[pt1]*nums[pt1];
            int n2 = nums[pt2]*nums[pt2];
            if (n1>n2){
                ans[pt--] = n1;
                pt1--;
            }else{
                ans[pt--] = n2;
                pt2++;
            }
        }
        return ans;
    }
};