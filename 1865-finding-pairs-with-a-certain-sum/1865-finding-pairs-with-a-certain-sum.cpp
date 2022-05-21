class FindSumPairs {
private:
    vector<int> small, big;
    unordered_map<int,int> marked;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        small = nums1;
        big = nums2;
        for (int i=0;i<int(big.size());++i){
            ++marked[big[i]];
        }
    }
    
    void add(int index, int val) {
        --marked[big[index]];
        big[index] += val;
        ++marked[big[index]];
    }
    
    int count(int tot) {
        int ans = 0;
        for (int i=0;i<int(small.size());++i){
            int num = tot - small[i];
            if (marked[num]){
                ans += marked[num];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */