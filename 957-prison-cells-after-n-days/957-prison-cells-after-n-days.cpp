class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector < vector<int> > day;
        map <vector <int>,int> vis;
        int idx=0;
        while (!vis.count(cells) && idx!=N){
            vis[cells]=idx++;
            day.push_back(cells);
            
            vector <int> tmp;
            for (int i=0;i<8;++i){
                if (i==0 || i==7){
                    tmp.push_back(0);
                    continue;
                }
                tmp.push_back(cells[i-1]==cells[i+1]);
            }
            
            cells.swap(tmp);
        }
        if (idx==N){
            return cells;
        }
        // N-(old)%(last-old)  +old -1
        int old=vis[cells], last=idx;
        int res= ((N-old)%(last-old)) + old ;
        //cout << old << " " << last << " " << res << endl;
        
        return day[res];
    }
};