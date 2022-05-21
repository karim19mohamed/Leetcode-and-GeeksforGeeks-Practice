class Solution {
    bool checker(string s,int &pt1, int &pt2){
        while(pt1<pt2){
            if (s[pt1]==s[pt2]){
                pt1++;
                pt2--;
            }else{
                return false;
            }
            // cout << pt1 << " " << pt2 << " " << s[pt1] << " " << s[pt2] << endl;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int pt1 = 0, pt2 = s.size()-1;
        if (checker(s,pt1, pt2))
            return 1;
        int cp_pt1 = pt1, cp_pt2 = pt2-1;
        pt1 = pt1+1;
        if (checker(s,pt1, pt2) || checker(s,cp_pt1, cp_pt2))
            return 1;
        return 0;
    }
};