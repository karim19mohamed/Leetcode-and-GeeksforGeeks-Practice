class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int space1 = 0, space2 = 0;
        int pt1 = s.size()-1, pt2 = t.size()-1;
        while(pt1>-1 || pt2>-1){
            bool flag = 0;
            while (pt1>-1 && s[pt1]=='#'){
                ++space1;
                --pt1;
                flag = 1;
            }
            while (pt2>-1 && t[pt2]=='#'){
                ++space2;
                --pt2;
                flag = 1;
            }
            while(pt1>-1 && space1 && s[pt1]!='#'){
                --pt1;
                --space1;
                flag = 1;
            }
            while(pt2>-1 && space2 && t[pt2]!='#'){
                --pt2;
                --space2;
                flag = 1;
            }
            if (flag)
                continue;
            if (pt1>-1 && pt2>-1 && s[pt1]!='#' && t[pt2]!='#'){
                if (s[pt1]==t[pt2]){
                    --pt1;
                    --pt2;
                    continue;
                }
            }
            return false;
        }
        return true;
    }
};