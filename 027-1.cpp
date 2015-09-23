/*
027. Remove Element
O(n)
*/

Given an array and a value, remove all instances of that value in place and return the new length.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n == 0) return n;
        int len = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != val) {
                nums[len] = nums[i];
                len++;
            }
        }
        return len;
    }
};
