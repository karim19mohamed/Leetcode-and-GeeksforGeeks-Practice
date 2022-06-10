class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[130];
        memset(cnt,0,sizeof(cnt));
        int pt1 = 0, pt2=0, ans =0;
        while (pt2<s.size()){
            char c1 = s[pt1], c2 = s[pt2];
            if (cnt[c2]==0){
                ++pt2;
                ++cnt[c2];
                ans = max(ans,pt2-pt1);
            }else{
                --cnt[c1];
                ++pt1;
            }
        }
        return ans;
    }
};