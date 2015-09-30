/*
287. Find the Duplicate Number My Submissions Question Solution 
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate element must exist. Assume that there is only one duplicate number, find the duplicate one.
Note:
You must not modify the array (assume the array is read only).
You must use only constant extra space.
Your runtime complexity should be less than O(n2).
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

/*
Time: O(n)
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int s = nums[0];
        int f = nums[nums[0]];
        while(f != s) {
            f = nums[nums[f]];
            s = nums[s];
        }
        int h = 0;
        while(h != s) {
            h = nums[h];
            s = nums[s];
        }
        return s;
    }
};
