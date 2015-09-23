/*
055. Jump Game

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() < 2) return true;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[0] == 1) {
                nums.erase(nums.begin());
            } else if(nums[0] == 0) {
                return false;
            } else {
                break;
            }
        }

        int n = nums.size();
        int step = 0;
        int start = 0;
        int end = n - 1;
        while(start < end) {
            if(nums[start] + start >= end) {
                step++;
                end = start;
                start = 0;
            } else {
                start++;
            }
        }
        return (start == 0);
    }
};
