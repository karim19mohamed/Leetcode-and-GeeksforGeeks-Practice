class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n){
            // cout << n << endl;
            if (n%2)
                ans++;
            n /= 2;
            
        }
        return ans;
    }
};