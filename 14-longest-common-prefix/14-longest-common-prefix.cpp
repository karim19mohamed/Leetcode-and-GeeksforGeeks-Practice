class Solution {
private:
    string get_common(string a, string b){
        string res = "";
        for (int i=0;i<min((int)a.size(),(int)b.size());++i)
            if (a[i]==b[i])
                res = res + a[i];
            else
                break;
        return res;
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for (int i=1;i<(int) strs.size();++i){
            res = get_common(res, strs[i]);
        }
        return res;
    }
};