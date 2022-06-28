class Solution {
public:
    int minDeletions(string s) {
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        for (auto c:s){
            ++cnt[c-'a'];
        }
        int ans = 0;
        sort(cnt, cnt+26);
        int least_num = cnt[25];
        for (int i=24;i>-1;--i){
            if (cnt[i]==0)
                break;
            if (cnt[i]>=least_num){
                ans += ((least_num>0)? cnt[i]-least_num+1 : cnt[i]-least_num);
                cnt[i] = ((least_num-1>=0)? least_num-1 : 0);
            }
            least_num = cnt[i];
        }
        return ans;
    }
};