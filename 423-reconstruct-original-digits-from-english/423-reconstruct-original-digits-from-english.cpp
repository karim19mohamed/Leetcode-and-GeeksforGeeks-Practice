class Solution {
private:
    string nums[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int cnt[300],ans[10];
    /*
    eorz  -> z (sure 0)
    otw   -> w (sure 2)
    foru  -> u (sure 4)
    eghit -> g (sure 8)
    isx   -> x (sure 6)
    eensv -> s (check after 6)
    efiv  -> v (check after 7)
    eno   -> o (check after 0,2,4)
    eehrt -> h (check after 8)
    einn  -> e (last)
    */
    string solver(){
        int idx[10] = {0,2,4,8,6,7,5,1,3,9};
        char st[10] = {'z','w','u','g','x','s','v','o','h','e'};
        for (int j=0;j<10;++j){
            int cur_idx = idx[j];
            char cur_st = st[j];
            if (cnt[cur_st]){
                int n = cnt[cur_st];
                for (int i=0;i<nums[cur_idx].size();++i){
                    char c = nums[cur_idx][i];
                    n = min(n,cnt[c]);
                }
                ans[cur_idx] = n;
                for (int i=0;i<nums[cur_idx].size();++i){
                    char c = nums[cur_idx][i];
                    cnt[c] -= n;
                }  
            }
        }
        string ret = "";
        for (int j=0;j<10;++j){
            for (int i=0;i<ans[j];++i){
                string cur_num = "0";
                cur_num[0] = cur_num[0]+j;
                ret = ret + cur_num;
            }
        }
        return ret;
    }
public:
    string originalDigits(string s) {
        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<int(s.size());++i){
            ++cnt[s[i]];
        }
        string ret = solver();
        return ret;
    }
};