class Solution {
public:
    int reverse(long long x) {
        if (x>INT_MAX || x<INT_MIN) return 0;
        long long ans = 0;
        bool negaitive = 0;
        if (x<0) negaitive=1,x*=-1;
        while (x){
            ans *= 10;
            int digit = x%10;
            ans += digit;
            x /=10;
        }
        if (ans>INT_MAX || ans<INT_MIN) return 0;
        return (negaitive)?-1*ans:ans;
    }
};