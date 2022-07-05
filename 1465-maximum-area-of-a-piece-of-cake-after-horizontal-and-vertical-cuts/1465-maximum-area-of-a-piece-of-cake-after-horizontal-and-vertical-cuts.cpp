class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const int M = 1e9 + 7;
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int x1 = 0, x2 = 0, szh = horizontalCuts.size();
        for (int i=0;i<szh-1;++i){
            if (horizontalCuts[i+1] - horizontalCuts[i] > x2 - x1){
                x1 = horizontalCuts[i];
                x2 = horizontalCuts[i+1];
            }
        }
        int y1 = 0, y2 = 0, szv = verticalCuts.size();
        for (int i=0;i<szv-1;++i){
            if (verticalCuts[i+1] - verticalCuts[i] > y2 - y1){
                y1 = verticalCuts[i];
                y2 = verticalCuts[i+1];
            }
        }
        long long ans = ( (long long)((x2-x1)%M) * (long long)((y2-y1)%M) ) % M;
        return ans;
    }
};