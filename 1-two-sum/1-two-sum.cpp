class Solution {
private:
     vector<int> tmp;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        tmp = nums;
        sort(tmp.begin(), tmp.end());
        int i=0,j=tmp.size()-1;
        vector<int> ans;
        while(i<j){
            if (tmp[i]+tmp[j]<target){
                ++i;
            }else if (tmp[i]+tmp[j]>target){
                --j;
            }else{
                for (int k=0;k<int(nums.size());++k){
                    if (nums[k]==tmp[i]){
                        ans.push_back(k);
                        break;
                    }
                }
                for (int k=int(nums.size())-1;k>=0;--k){
                    if (nums[k]==tmp[j]){
                        ans.push_back(k);
                        break;
                    }
                }
                break;
            }
        }
        return ans;
    }
};