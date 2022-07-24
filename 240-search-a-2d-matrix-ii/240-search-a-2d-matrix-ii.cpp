class Solution {
    int m = 0;
    int n = 0;
    bool binary_search(const vector<int> &m, const int &target){
        int st = 0, en = n-1;
        while(st<en){ // FFFFFFFTTTT
            int mid = st + (en-st)/2;
            (m[mid]>=target)? en = mid : st = mid + 1;
        }
        return m[st]==target;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        bool ans = false;
        for (int i=0;i<m;++i){
            if (target<matrix[i][0])
                break;
            if (target>=matrix[i][0] && target<=matrix[i][n-1])
                ans |= binary_search(matrix[i], target);
        }
        return ans;
    }
};