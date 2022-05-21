class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        for (int i=0;i<(int)haystack.size();++i){
            bool flag = true;
            int idx = i;
            for (int j=0;j<(int)needle.size();++j){
                if (haystack[idx++]!=needle[j]){
                    flag = false;
                    break;
                }
            }
            if (flag)
                return i;
        }
        return ans;
    }
};