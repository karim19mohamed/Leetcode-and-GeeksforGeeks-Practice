class Solution {
private:
    vector <int> ans;
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector <int> ans(A.size(),-1);
        sort(A.begin(),A.end());
        priority_queue<pair<int,int>> q;
        for(int i=0;i<int(B.size());++i){
            q.push(make_pair(-B[i],i));
        }
        int idx = 0;
        while(!q.empty()){
            int curr = -q.top().first;
            int B_idx = q.top().second;
            while(idx<A.size()){
                if (A[idx]>curr){
                    ans[B_idx] = A[idx];
                    A[idx] = -1;
                    break;
                }
                ++idx;
            }
            q.pop();
        }
        idx = 0;
        for (int i=0;i<int(A.size());++i){
            if (A[i]==-1) continue;
            while(idx<ans.size()){
                if (ans[idx]==-1){
                    ans[idx] = A[i];
                    break;
                }
                ++idx;
            }
        }
        return ans;
    }
};