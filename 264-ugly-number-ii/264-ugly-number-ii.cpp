typedef long long ll;
class Solution {
private:
    vector <ll> ans;
    void bfs(){
        set<ll> q;
        q.insert(1);
        set<ll>::iterator it=q.begin();
        while (ans.size()<1699){
            ll t=*it;
            ans.push_back(t);
            q.insert(t*2);
            q.insert(t*3);
            q.insert(t*5);
            ++it;
        }
    }
    
public:
    Solution(){
        bfs();
    }
    int nthUglyNumber(int n) {
        return ans[n-1];
    }
};