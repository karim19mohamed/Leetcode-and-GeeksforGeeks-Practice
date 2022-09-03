class Solution {
    vector<int> ans;
    int k;
    void rec(int num, int n){
        if (n==0){
            ans.push_back(num);
            return;
        }
        int last_dig = num%10;
        if (last_dig+k<10)
            rec(num*10+(last_dig+k),n-1);
        if (k && last_dig-k>-1)
            rec(num*10+(last_dig-k),n-1);
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        this->k = k;
        // ans.clear();
        for (int i=1;i<10;++i)
            rec(i, n-1);
        return ans;
    }
};