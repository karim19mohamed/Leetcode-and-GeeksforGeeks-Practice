class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int st=0, en = letters.size()-1;
        while(st<en){
            int mid = st + (en-st)/2;
            (letters[mid]>target)? en = mid : st = mid+1;
        }
        return (letters[st]>target)? letters[st] : letters[0];
    }
};