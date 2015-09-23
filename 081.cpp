/*
081. Search in Rotated Sorted Array II

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
*/

class Solution {
private:
    bool find(vector<int>& nums, int l, int r, int target) {
        if (l > r) {
            return false;
        }
        int mid = (l + r) >> 1;
        if (nums[mid] == target) {
            return true;
        }
        else if (nums[l] < nums[r]) {
            return nums[mid] < target ? find(nums, mid + 1, r, target) : find(nums, l, mid - 1, target);
        }        
        else {
            return find(nums, l, mid - 1, target) || find(nums, mid + 1, r, target);
        }
    }

public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        return find(nums, 0, n - 1, target);
    }
};
