typedef long long ll;
class Solution {
private:
    ll d=26;
    //const ll PRIME=1000000007; 
    //const ll PRIME=100000000003;
     ll PRIME=100000000003;
    void initiate_hash(string &S,const int &sz,ll &num,ll &h){
        for (int i = 0; i < sz-1; i++) h = (h * d) % PRIME;
        for (int i = 0; i < sz; i++){
            ll c = S[i]-'a';
            num = (  ( (d * num ) % PRIME ) + c  ) % PRIME;
        }
    }
    ll update_hash(string &S,const int &sz,const int &idx,ll num,ll h){
        ll c1 = S[idx]-'a' , c2 = S[idx-sz]-'a';
        num =  ( PRIME + num -  ( (h * c2) % PRIME ) ) % PRIME ;
        num = ( ( ( d * num ) % PRIME) + c1   ) % PRIME;
        return num;
    }
    
    int chk(int mid,string &S){
        int idx=0;
        unordered_map <ll,vector<int> > freq;
        ll num=0,h=1;
        initiate_hash(S,mid,num,h);
        
        freq[num].push_back(0);
        for (int i=mid;i<S.size();++i){
            num=update_hash(S,mid,i,num,h);
            //
            if (freq[num].size()>0){
                for (auto j:freq[num]){
                    int tmp=j,curr=i-mid+1;
                    bool same=1;
                    for (int ww=0;ww<mid;++ww)
                        if (S[curr+ww]!=S[tmp+ww]){
                            same=0;
                            break;
                        }
                    if (same) return i-mid+1;
                }
            }
            freq[num].push_back(i-mid+1);
        }
        return -1;
    }
    
public:
    string longestDupSubstring(string S) {
        if (!S.size()) return "";
        string ans="";
        int ss=0,ee=S.size()-1,idx;
        while(ss<ee){
            int mid=ss+(ee-ss+1)/2;
            int tmp=chk(mid,S);
            //cout << mid << " " << tmp << endl;
            if (tmp!=-1) idx=tmp;
            (tmp!=-1)? ss=mid : ee=mid-1;
        }
        //cout << "sadasdasd   " << idx << " " << ss << endl;
        for (int i=idx;i<idx+ss;++i) ans.push_back(S[i]);
        return ans;
    }
};