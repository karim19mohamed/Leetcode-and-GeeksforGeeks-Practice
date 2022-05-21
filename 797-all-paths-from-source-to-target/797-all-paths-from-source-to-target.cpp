class Solution {
    vector<vector<int>> ans;
    vector<int> res; 
    // vector<bool> vis;
    void dfs(vector<vector<int>>& graph, int n, int idx){
        res[idx] = n;
        if (n==graph.size()-1){
            vector<int> tmp;
            for(int i=0;i<=idx;++i)
                tmp.push_back(res[i]);
            ans.push_back(tmp);
            return;
        }
        for(auto v:graph[n]){
            dfs(graph, v, idx+1);
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> tmp;
        swap(ans, tmp);
        res.resize(graph.size(),0);
        dfs(graph, 0, 0);
        return ans;
    }
};