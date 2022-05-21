class Solution {
private:
    bool chk(unsigned long long mid,int n){
        unsigned long long num=mid*(mid-1)/2;
        return num<=n;
    }
public:
    int arrangeCoins(int n) {
        if (n==0)
            return 0;
        if (n==1)
            return 1;
        int ans=0;
        unsigned long long s=2,e=n;
        while(s<e){
            unsigned long long mid=s+(e-s+1)/2;
            (chk(mid,n))? s=mid : e=mid-1;
        }
        ans=s-1;
        return ans;
    }
};