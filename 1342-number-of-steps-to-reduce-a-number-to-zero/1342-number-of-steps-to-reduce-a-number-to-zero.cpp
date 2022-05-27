class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while(num){
            ++ans;
            (num%2==0)? num /= 2 : num--;
        }
        return ans;
    }
};