class Solution {
private:
    int vid=0;
    vector<vector<int> > vis;
    
    int i_m[4]={ 1,-1, 0, 0};
    int j_m[4]={ 0, 0, 1,-1};

    struct node{
        int x,y;
    };

    void bfs(node src,vector<vector<char>>& board){
        if (board[src.x][src.y]=='X' || vis[src.x][src.y]!=0) return;
        int N=board.size(),M=board[0].size();
        bool bounded=1;
        //cout << src.x <<" " << src.y << endl;
        
        queue<node> q;
        q.push(src);
        vis[src.x][src.y]=++vid;
        
        while (!q.empty()){
            
            int qsz=q.size();
            while (qsz--){
                node u=q.front();
                q.pop();
                if (board[u.x][u.y]=='X') continue;
                for (int i=0;i<4;++i){
                    int ii=i_m[i],jj=j_m[i];
                    
                    if (u.x+ii<0 || u.x+ii>=N){
                        bounded=0;
                        continue;
                    }
                    if (u.y+jj<0 || u.y+jj>=M){
                        bounded=0;
                        continue;
                    }
                    
                    if (vis[u.x+ii][u.y+jj]==vid) continue;
                    q.push({u.x+ii,u.y+jj});
                    vis[u.x+ii][u.y+jj]=vid;
                }
            }
        }
        if (!bounded) return;
        //cout << src.x <<" " << src.y << endl;
        for (int i=0;i<N;++i){
            for (int j=0;j<M;++j){
                if (vis[i][j]==vid) board[i][j]='X';
            }
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.size()==0) return;
        int N=board.size(),M=board[0].size();
        vector <int> tmp(M,0);
        for (int i=0;i<N;++i) vis.push_back(tmp);
        
        for (int i=0;i<N;++i){
            for (int j=0;j<M;++j){
                node nn={i,j};
                bfs(nn,board);
            }
        }
    }
};















