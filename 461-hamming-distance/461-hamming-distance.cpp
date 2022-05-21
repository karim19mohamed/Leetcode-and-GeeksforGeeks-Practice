class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> x_bits=x, y_bits=y;
        //cout << x_bits[0] << " " << y_bits[0] << endl;
        int ans=0;
        for (int i=0;i<32;++i){
            if (x_bits[i]!=y_bits[i]) ++ans;
        }
        return ans;
    }
};