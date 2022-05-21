class Solution {
private:
    int rec(int n){
        if (n==0)
            return 1;
        if (n<0)
            return 0;
        int res = rec(n-1) + rec(n-2);
        return res;
    }
    int fib(int n){
        int ans = 1, pre = 0;
        for (int i=1;i<=n;++i){
            int tmp = ans;
            ans = ans + pre;
            pre = tmp;
        }
        return ans;
    }
public:
    int climbStairs(int n) {
        return fib(n);
    }
};