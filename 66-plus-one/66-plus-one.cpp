class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector <int> ans;
        int sum=digits.back()+1;
        int carier=sum/10;
        sum%=10;
        ans.push_back(sum);
        int idx=digits.size()-2;
        while(idx+1){
            sum=digits[idx--]+carier;
            carier=sum/10;
            sum%=10;
            ans.push_back(sum);
        }
        if (carier)
            ans.push_back(carier);
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};