class Solution {
public:
    bool isHappy(int n) {
        int tmp = 0;
        map<int,bool> m;
        while (1){
            while(n){
                int num = n%10;
                n/=10;
                num = num * num;
                tmp += num;
            }
            n = tmp;
            tmp = 0;
            if (n==1)
                break;
            if (m[n])
                break;
            m[n] = 1;
        }
        return (n==1);
    }
};