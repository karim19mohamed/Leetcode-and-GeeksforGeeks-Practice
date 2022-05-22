class Solution {
    int solver1(uint32_t n){
        int ans = 0;
        while (n){
            if (n%2)
                ans++;
            n /= 2;
            
        }
        return ans;
    }
    int solver2(uint32_t n){
        int ans = 0;
        uint32_t mask = 1;
        for (int i=0;i<32;++i){
            if (n&mask)
                ans++;
            mask <<= 1;
        }
        return ans;
    }
public:
    int hammingWeight(uint32_t n) {
        return solver2(n);
    }
};