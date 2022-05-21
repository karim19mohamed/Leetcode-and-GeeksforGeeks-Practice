class Solution {
    double get_power(double x, int n){
        if(n==0)
            return 1;
        if(n==1 || n==-1)
            return x;
        double res = 1.0;
        res *= get_power(x, n/2);
        res = res*res;
        if (n%2)
            res *= x;
        return res;
    }
public:
    double myPow(double x, int n) {
        double ans = 0.0;
        ans = get_power(x, n);
        if (n<0){
            ans = 1/ans;
        }
        return ans;
    }
};