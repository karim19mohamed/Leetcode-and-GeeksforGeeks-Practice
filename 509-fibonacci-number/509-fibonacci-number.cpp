class Solution {
public:
    int fib(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        int f_pre2 = 0, f_pre1 = 1;
        for (int i=2;i<=n;++i){
            int tmp = f_pre1 + f_pre2;
            f_pre2 = f_pre1;
            f_pre1 = tmp;
        }
        return f_pre1;
    }
};