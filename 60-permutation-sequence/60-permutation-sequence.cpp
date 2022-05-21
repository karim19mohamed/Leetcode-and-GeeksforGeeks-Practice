class Solution {
private:
    bool chk[10];
    int all=1;
public:
    string getPermutation(int n, int k) {
        string ans="";
        for (int i=1;i<=n;++i){
            chk[i]=0;
            all*=i;
        }
        int tmp=n;
        for (int i=0;i<n;++i){
            all/=tmp;
            --tmp;
            int idx=(k+all-1)/all , num;
            //cout << idx << endl;
            for (int j=1;j<idx+1;++j){
                if (chk[j]){
                    ++idx;
                    continue;
                }else{
                    num=j;
                }
            }
            ans+=('0'+num);
            chk[num]=1;
            k = (k%all)? k%all : all;
            cout << ans << endl;
        }
        return ans;
    }
};