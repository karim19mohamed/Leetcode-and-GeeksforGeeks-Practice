class Solution {
public:
    int minSwaps(string s) {
        int ones = 0, zeros = 0;
        int n1 = 0, n2 = 1;
        int res1 = 0, res2 = 0;
        for (int i=0;i<int(s.size());++i){
            int num = s[i] - '0';
            (num)? ++ones: ++zeros;
            if (num!=n1) ++res1;
            if (num!=n2) ++res2;
            n1 ^= 1;
            n2 ^= 1;
        }
        if (abs(ones-zeros)>1)
            return -1;
        res1 /= 2;
        res2 /= 2;
        int ans = 0;
        if (ones>zeros){
            ans = res2;
        }else if (zeros>ones){
            ans = res1;
        }else{
            ans = min(res1,res2);
        }
        return ans;
    }
};