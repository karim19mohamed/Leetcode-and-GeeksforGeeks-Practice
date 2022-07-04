class Solution {
    vector<int> modify_zeros(vector<int> ratings){
        bool flag = 0;
        for (auto r:ratings)
            if (!r){
                flag = 1;
                break;
            }
        if (flag){
            for (auto &r:ratings)
                r += 1;
        }
        return ratings;
    }
public:
    int candy(vector<int>& ratings) {
        vector<int> new_ratings = modify_zeros(ratings);
        int ans = 0,
            sz = new_ratings.size(),
            num = 1;
        vector<int> candy(sz,0);
        candy[0] = 1;
        for (int i=1;i<sz;++i){
            if (new_ratings[i]>new_ratings[i-1]){
                ++num;
            }else{
                num = 1;
            }
            candy[i] = num;
        }
        for (int i=sz-2;i>-1;--i){
            if (new_ratings[i]>new_ratings[i+1]){
                if (candy[i]<=candy[i+1]){
                    candy[i] = candy[i+1] + 1;
                }
            }
        }
        for (auto c : candy)
            ans += c;
        return ans;
    }
};
// 1+2+1+2+3+4+5+1+1+1+2