/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int st = 0, en = 1e4;
        while(st<en){
            int mid = st + (en-st+1)/2;
            (reader.get(mid)<=target)? st = mid : en = mid-1;
        }
        if (reader.get(st)==target)
            return st;
        return -1;
    }
};