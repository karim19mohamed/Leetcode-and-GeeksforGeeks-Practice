class Solution {
private:
    bool chk(int n,vector<int>& citations){
        int freq=0;
        for (int i=0;i<citations.size();++i) if (citations[i]>=n) ++freq;
        return n<=freq;
    }
    
public:
    int hIndex(vector<int>& citations) {
        if (!citations.size()) return 0;
        int s=0,e=citations.back();
        while(s<e){
            int mid=s+(e-s+1)/2;
            (chk(mid,citations))? s=mid : e=mid-1;
        }
        return s;
    }
};