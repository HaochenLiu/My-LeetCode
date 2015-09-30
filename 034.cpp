/*
034. Search for a Range

Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

/*
Time: O(logn)
Space: O(1)
Extra space: O(1)
n is length of the array.
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res(2, -1);
        int lower = getLowerBound(nums, target);
        int upper = getUpperBound(nums, target);
        if(lower <= upper) {
            res[0] = lower;
            res[1] = upper;
        }
        return res;
    }
    
    int getLowerBound(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    int getUpperBound(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};
