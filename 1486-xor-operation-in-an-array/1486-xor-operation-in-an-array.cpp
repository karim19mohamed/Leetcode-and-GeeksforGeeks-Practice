class Solution {
private:
    const int N=1009;
    int num[1009];
public:
    int xorOperation(int n, int start) {
        num[0]=start;
        int ans=start;
        for (int i=1;i<n;++i){
            num[i]= start + 2*i;
            ans=ans^num[i];
        }
        return ans;
    }
};