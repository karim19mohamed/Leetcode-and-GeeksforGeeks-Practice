class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        bool ans = true;
        sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){
            return a[0]<b[0];
        });
        int st = 0;
        for (int i=0;i<intervals.size();++i){
            if (st <= intervals[i][0]){
                st = intervals[i][1];
            }else{
                ans = false;
                break;
            }
        }
        return ans;
    }
};