typedef long long ll;
class Solution {
private:
    int vid=0,vis[109][109];
    ll dfs(int i,int j,const int &n,const int &m){
        if (i==n-1 && j==m-1) 
            return 1;
        if (i<0 || i>=n || j<0 || j>=m)
            return 0;
        ll num=0;
        int n_i=i+1,n_j=j+1;
        num+=dfs(i+1,j,n,m)+dfs(i,j+1,n,m);
        return num;
    }
public:
    int uniquePaths(int m, int n) {
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                vis[i][j]=0;
        vis[n-1][m-1]=1;
        for (int i=n-1;i>=0;--i){
            for (int j=m-1;j>=0;--j){
                if (i+1<n)
                    vis[i][j]+=vis[i+1][j];
                if (j+1<m)
                    vis[i][j]+=vis[i][j+1];
            }
        }
        cout<<vis[n-1][m-1]<<endl;
        return vis[0][0];
    }
};