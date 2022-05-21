class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> tmp;
        ans.push_back(tmp);
        ans[0].push_back(1);
        int sz = 1;
        numRows--;
        while(numRows--){
            sz++;
            vector<int> tmp;
            ans.push_back(tmp);
            ans[sz-1].push_back(1);
            for (int i=0;i<(int)ans[sz-2].size()-1;++i){
                ans[sz-1].push_back(ans[sz-2][i]+ans[sz-2][i+1]);
                cout << sz << " " << i << endl;
            }
            ans[sz-1].push_back(1);
        }
        
        return ans;
    }
};