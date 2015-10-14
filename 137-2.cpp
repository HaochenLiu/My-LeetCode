/*
137. Single Number II

http://www.cnblogs.com/x1957/p/3373994.html
Given an array of integers, every element appears three times except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0;
        int two = 0;
        int three = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            two |= (one & nums[i]);
            one ^= nums[i];
            three = two & one;
            two &= ~three;
            one &= ~three;
        }
        return one;
    }
};
