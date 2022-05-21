class Solution {
private:
    map<int,bool> m;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int ans = 1;
        m[0] = 1;
        bool change = true;
        while(change){
            change = false;
            for (int i=0;i<int(rooms.size());++i){
                if (m[i]){
                    for (int j=0;j<int(rooms[i].size());++j){
                        int cur_room = rooms[i][j];
                        if(!m[cur_room]) 
                            m[cur_room]=1,++ans,change=true;
                    }
                }
            }
        }
        return ans == int(rooms.size());
    }
};