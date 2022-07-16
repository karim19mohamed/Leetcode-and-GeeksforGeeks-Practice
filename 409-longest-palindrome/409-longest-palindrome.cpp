class Solution {
    int N = 123;
public:
    int longestPalindrome(string s) {
        int cnt[N];
        memset(cnt,0,sizeof(cnt));
        for (auto c: s)
            ++cnt[c];
        int ans = 0;
        bool odd_flag = false;
        for (int i=0;i<N;++i){
            if (cnt[i]%2){
                odd_flag = true;
            }
            int num = cnt[i] / 2;
            ans += num*2;
        }
        if (odd_flag)
            ++ans;
        return ans;
    }
};