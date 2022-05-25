class Solution {
    int divider(int n){
        while(n%2==0 || n%3==0 || n%5==0){
            if (n%2==0)
                n /=2;
            if (n%3==0)
                n /=3;
            if (n%5==0)
                n /=5;
        }
        return n;
    }
public:
    bool isUgly(int n) {
        if (n<=0)
            return false;
        n = divider(n);
        return n==1;
    }
};