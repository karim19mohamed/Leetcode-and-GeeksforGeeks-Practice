class Solution {
public:
    int mySqrt(int x) {
        unsigned int st = 0, en = 46341;
        while(st<en){
            unsigned int mid = st + (en-st+1)/2;
            (mid*mid<=x)? st = mid : en = mid-1;
        }
        return st;
    }
};