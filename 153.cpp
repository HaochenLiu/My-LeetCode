/*
153. Find Minimum in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    void bs(vector<int> &num, int beg,int end, int &res){
        if (beg > end){ return; }
        else {
            int mid = beg + (end - beg) / 2; //get middle index
            if (num[mid] < num[end]){  // right part orderend
                res = min(res, num[mid]); //get right part min
                bs(num, beg, mid - 1, res); //search left part
            } else {  //right part unorderend
                res = min(res, num[beg]); //get left part min
                bs(num, mid + 1, end, res); //search right part
            }
        }
    }
    int findMin(vector<int> &num) {
        int n = num.size();
        int res = num[0];
        bs(num, 0, n - 1, res);
        return res;
    }
};
