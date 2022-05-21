

class Solution {
private:
    const char x[4] = {'0','1','0','1'};
    const int y[4] = {0,0,1,1};
    void sum_both(string &a, string &b, string &ans){
        int rem = 0;
        int sum = 0;
        int st = 0;
        int j = (int)b.size()-1;
        for (int i = (int)a.size()-1;i>=0;--i){
            sum = a[i] - '0' + b[j--] - '0' + rem;
            ans[st++] = x[sum];
            rem = y[sum];
        }
        for (;j>=0;--j){
            sum = b[j] - '0' + rem;
            ans[st++] = x[sum];
            rem = y[sum];
        }
        if (rem)
            ans = ans + "1";
    }
public:
    string addBinary(string a, string b) {
        if (a.size()>b.size())
            swap(a,b);
        // a is smaller
        string ans = b;
        sum_both(a, b, ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};