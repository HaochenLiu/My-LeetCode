/*
026. Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,
Given input array nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

/*
Time: O(n)
Space: O(n)
Extra space: O(1)
n is number of nodes
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int len = 0;
        for(int i = 1; i < n; i++) {
            if(nums[len] != nums[i]) {
                len++;
                nums[len] = nums[i];
            }
        }
        return len + 1;
    }
};
