class Solution {
private:
    vector<vector<int>> powers;
    void generate(){
        long long num = 1;
        while (num<2e9){
            vector<int> power;
            long long tmp = num;
            while (tmp){
                power.push_back(tmp%10);
                tmp /= 10;
            }
            sort(power.begin(),power.end());
            powers.push_back(power);
            num *= 2;
        }
    }
    bool chk(vector <int> digits){
        for (int i=0;i<int(powers.size());++i){
            if (powers[i].size() != digits.size()) continue;
            bool ans = 1;
            for (int j=0;j<int(powers[i].size());++j){
                if (powers[i][j]!=digits[j]){
                    ans = 0;
                    break;
                }
            }
            if (ans) return 1;
        }
        return 0;
    }
public:
    Solution(){
        generate();
    }
    bool reorderedPowerOf2(int N) {
        vector <int> digits;
        while (N){
            digits.push_back(N%10);
            N /= 10;
        }
        sort(digits.begin(),digits.end());
        bool ans = chk(digits);
        return ans;
    }
};