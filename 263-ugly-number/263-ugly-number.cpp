class Solution {
    int divider(int n, int num){
        while(n%num==0){
            n /=num;
        }
        return n;
    }
public:
    bool isUgly(int n) {
        if (n<=0)
            return false;
        n = divider(n, 2);
        n = divider(n, 3);
        n = divider(n, 5);
        return n==1;
    }
};