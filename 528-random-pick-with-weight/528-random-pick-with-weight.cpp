class Solution {
private:
    int sum;
    vector <int> cdf;
    
public:
    int binary_search(int num){
        int s=0,e=cdf.size()-1;
        while (s<e){
            int mid = s+(e-s)/2;
            (cdf[mid]<num)? s=mid+1 : e=mid;
        }
        return s;
    }
    Solution(vector<int>& w) {
        cdf.push_back(w[0]);
        sum=w[0];
        for (int i=1;i<w.size();++i){
            sum+=w[i];
            cdf.push_back(cdf[cdf.size()-1]+w[i]);
        }
    }
    
    int pickIndex() {
        int r= rand() % cdf.back() + 1;
        return binary_search(r);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */