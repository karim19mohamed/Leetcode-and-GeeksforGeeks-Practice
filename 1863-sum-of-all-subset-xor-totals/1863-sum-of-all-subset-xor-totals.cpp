class Solution {
private:
    vector<int> a;
    int rec(int idx, int cur){
        if (idx==-1) return 0;
        int ret = rec(idx-1, cur);
        int res = cur^a[idx];
        ret += res + rec(idx-1,res);
        return ret;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        a = nums;
        int ans = rec(nums.size()-1,0);
        return ans;
    }
};