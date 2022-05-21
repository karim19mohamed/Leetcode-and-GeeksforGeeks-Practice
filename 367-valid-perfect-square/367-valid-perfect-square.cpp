class Solution {
public:
    bool isPerfectSquare(int num) {
        int st = 0, en = 46340;
        while(st<en){
            int mid = st + (en-st+1)/2;
            (mid*mid<=num)? st = mid : en = mid-1;
        }
        return st*st==num;
    }
};