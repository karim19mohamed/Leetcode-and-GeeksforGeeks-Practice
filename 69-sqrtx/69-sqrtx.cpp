class Solution {
public:
    int mySqrt(int x) {
        int ans = 0, pre = 0;
        while (ans<=46340){
            if (ans*ans == x)
                return ans;
            if (ans*ans > x)
                break;
            pre = ans;
            ++ans;
        }
        return pre;
    }
};