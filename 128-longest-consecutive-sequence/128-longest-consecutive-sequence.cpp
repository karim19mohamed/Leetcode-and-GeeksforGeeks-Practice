class Solution {
    int get_longest(map<int,bool> &m, int num){
        int res = 0,
            tmp = num;
        while(m[tmp]){
            ++res;
            m[tmp] = 0;
            --tmp;
        }
        tmp = num + 1;
        while(m[tmp]){
            ++res;
            m[tmp] = 0;
            ++tmp;
        }
        return res;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool> m;
        for (auto num:nums){
            m[num] = 1;
        }
        int ans = 0;
        for (auto num:nums)
            ans = max(ans,get_longest(m, num));
        return ans;
    }
};