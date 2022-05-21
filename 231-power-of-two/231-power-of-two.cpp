class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long pw=1;
        while (pw<n){
            pw*=2;
        }
        return pw==n;
    }
};