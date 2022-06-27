class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        int sz = n.size();
        while (1){
            bool flag = false;
            for (int i=0;i<sz;++i){
                if (n[i]>'0'){
                    n[i] = n[i] - 1;
                    flag = true;
                }
            }
            if (flag){
                ++ans;
            }else{
                break;
            }
        }
        return ans;
    }
};