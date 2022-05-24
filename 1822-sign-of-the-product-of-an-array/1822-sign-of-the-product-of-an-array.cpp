class Solution {
    int signFunc(int num){
        if (num < 0)
            return -1;
        else if (num>0)
            return 1;
        return 0;
    }
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (auto num:nums)
            sign *= signFunc(num);
        return sign;
    }
};