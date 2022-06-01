class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int pt1=0, pt2=0;
        while (pt1<nums1.size() && pt2<nums2.size()){
            if (nums1[pt1]==nums2[pt2]){
                ans.push_back(nums1[pt1]);
                ++pt1;
                ++pt2;
            }else if (nums1[pt1]<nums2[pt2]){
                ++pt1;
            }else{
                ++pt2;
            }
                
        }
        return ans;
    }
};