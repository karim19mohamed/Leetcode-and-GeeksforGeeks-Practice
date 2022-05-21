class Solution {
private:
    string s[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string Digits;
    void rec(int idx, string res, vector<string> &ans){
        if (idx==Digits.size()){
            if (res.size()!=0)
                ans.push_back(res);
            return;
        }
        int cur = Digits[idx] - '0';
        // cout << cur << endl;
        string cur_s = s[cur];
        for (int i=0;i<(int)cur_s.size();++i){
            rec(idx+1, res+cur_s[i], ans);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        Digits = digits;
        rec(0, "", ans);
        return ans;
    }
};