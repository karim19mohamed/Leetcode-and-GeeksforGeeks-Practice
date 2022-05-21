class Solution {
    vector<bool> vis;
    void dfs(const vector<int> *adj, int n){
        vis[n] = 1;
        for(auto v: adj[n]){
            if(!vis[v])
                dfs(adj, v);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for (auto v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vis.resize(n,0);
        dfs(adj, source);
        return vis[destination];
    }
};