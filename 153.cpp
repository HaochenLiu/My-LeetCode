/*
153. Find Minimum in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int res = nums[0];
        while(l <= r) {
            int m = l + (r - l) / 2;
            res = min(res, nums[m]);
            if(nums[l] < nums[r]) {
                r = m - 1;
            } else {
                if(nums[m] >= nums[l]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        
        return res;
    }
};
