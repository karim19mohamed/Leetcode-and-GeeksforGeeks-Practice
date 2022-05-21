class Solution {
    vector<int> naive(int rowIndex){
        vector<vector<int>> res;
        res.push_back({1});
        res.push_back({1,1});
        int row = 1;
        while(row<rowIndex){
            ++row;
            int sz = row - 1;
            vector<int> tmp{1};
            vector<int> pre = res.back();
            for(int i=0;i<sz;++i){
                tmp.push_back(pre[i]+pre[i+1]);
            }
            tmp.push_back(1);
            res.push_back(tmp);
        }
        return res[rowIndex];
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = naive(rowIndex);
        return ans;
    }
};