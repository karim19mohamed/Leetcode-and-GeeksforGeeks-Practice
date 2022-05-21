class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        vector<int> min_vals(sz);
        vector<int> max_vals(sz);
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        for (int i=0;i<sz;++i){
            min_val = min(min_val, prices[i]);
            min_vals[i] = min_val;
        }
        for (int i=sz-1;i>=0;--i){
            max_val = max(max_val, prices[i]);
            max_vals[i] = max_val;
        }
        int dif = 0;
        for (int i=0;i<sz;++i)
            dif = max(dif,max_vals[i]-min_vals[i]);
        return dif;
    }
};