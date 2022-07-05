class Solution {
    void greedy(int& a1, int& a2, vector<int>& v){
        int sz = v.size();
        for (int i=0;i<sz-1;++i){
            if (v[i+1] - v[i] > a2 - a1){
                a1 = v[i];
                a2 = v[i+1];
            }
        }
    }
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const int M = 1e9 + 7;
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int x1 = 0, x2 = 0;
        greedy(x1, x2, horizontalCuts);
        int y1 = 0, y2 = 0;
        greedy(y1, y2, verticalCuts);
        long long ans = ( (long long)((x2-x1)%M) * (long long)((y2-y1)%M) ) % M;
        return ans;
    }
};