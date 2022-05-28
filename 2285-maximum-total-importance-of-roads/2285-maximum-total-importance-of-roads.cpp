class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long num_edges[n];
        memset(num_edges,0,sizeof(num_edges));
        for (auto road:roads){
            num_edges[road[0]]++;
            num_edges[road[1]]++;
        }
        sort(num_edges,num_edges+n);
        long long ans = 0;
        for (long long i=n;i>0;--i){
            ans += i * num_edges[i-1];
        }
        return ans;
    }
};