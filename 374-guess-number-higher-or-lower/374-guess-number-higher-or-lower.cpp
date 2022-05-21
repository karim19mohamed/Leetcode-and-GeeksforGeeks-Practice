/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int st = 1, en = n;
        while(st<en){
            int mid = st + (en-st+1)/2;
            (guess(mid)>=0)? st = mid: en = mid-1;
        }
        return st;
    }
};