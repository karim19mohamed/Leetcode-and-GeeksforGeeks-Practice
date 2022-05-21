class Solution {
    int sum_digits(int n){
        int res = 0;
        while(n){
            res += n%10;
            n/=10;
        }
        return res;
    }
    int sum_better(int n){
        if (n==0)
            return 0;
        if (n%9==0)
            return 9;
        return n%9;
    }
public:
    int addDigits(int num) {
        // int ans = num;
        // while(ans/10){
        //     ans = sum_digits(ans);
        // }
        // return ans;
        return sum_better(num);
    }
};