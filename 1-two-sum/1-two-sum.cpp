class Solution {
private:
    map<int,int> m;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        for (int i=0;i<(int)nums.size();++i){
            m[nums[i]]++;
        }
        int rem = 0;
        for (int i=0;i<(int)nums.size();++i){
            m[nums[i]]--;
            if (m[target-nums[i]]){
                ans.push_back(i);
                rem = target-nums[i];
                break;
            }
            m[nums[i]]++;
        }
        for (int i=(int)nums.size()-1;i>=0;--i)
            if (nums[i]==rem){
                ans.push_back(i);
                break;
            }
        return ans;
    }
};