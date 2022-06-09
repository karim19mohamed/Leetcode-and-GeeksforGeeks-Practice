class Solution {
    int binary_search(vector<int>& numbers, int num, int st){
        // TTTTTTTTFFFF
        int en = numbers.size()-1;
        while(st<en){
            int mid = st + (en-st+1)/2;
            (numbers[mid]<=num)? st=mid : en =mid-1;
        }
        return st;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for (int i=0;i<(int)numbers.size();++i){
            int dif = target-numbers[i];
            int idx = binary_search(numbers, dif, i+1);
            if (numbers[idx]+numbers[i]==target){
                ans.push_back(i+1);
                ans.push_back(idx+1);
                break;
            }
        }
        return ans;
    }
};