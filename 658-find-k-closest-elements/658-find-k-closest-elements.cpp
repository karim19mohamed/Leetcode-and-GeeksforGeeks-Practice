class Solution {
    int findelement(vector<int>& arr, int x){
        int st = 0, en = arr.size()-1;
        while(st<en){
            int mid = st + (en-st+1)/2;
            (arr[mid]<=x)? st=mid: en=mid-1;
        }
        
        if (st != arr.size()-1 && abs(arr[st]-x)>abs(arr[st+1]-x))
            return st+1;
        return st;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos = findelement(arr, x);
        cout << pos << endl;
        int st = pos, en = pos+1, tot_sz = arr.size();
        k--;
        while(k--){
            if (st-1>=0){
                if (en<tot_sz){
                    if (abs(arr[st-1]-x)>abs(arr[en]-x)){
                        ++en;
                    }else{
                        --st;
                    }
                }else{
                    --st;
                }
            }else{
                ++en;
            }
        }
        vector<int>::const_iterator first = arr.begin() + st;
        vector<int>::const_iterator last = arr.begin() + en;
        vector<int> res(first, last);
        return res;
    }
};