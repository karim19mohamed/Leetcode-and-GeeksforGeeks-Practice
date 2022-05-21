#include <algorithm>

class Solution {
private:
    map<string,int> m;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> tmp = strs;
        int indx = 1;
        for (int i=0;i<(int)tmp.size();++i){
            sort(tmp[i].begin(),tmp[i].end());
            if (m[tmp[i]]==0)
                m[tmp[i]] = indx++;
        }
        vector<vector<string>> ans(indx-1);
        for (int i=0;i<(int)strs.size();++i){
            ans[m[tmp[i]]-1].push_back(strs[i]);
        }
        
        return ans;
    }
};