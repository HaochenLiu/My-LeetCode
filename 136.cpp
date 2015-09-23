/*
136. Single Number
http://www.cnblogs.com/heyonggang/p/3376679.html

Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            res ^= nums[i];
        }
        return res;
    }
};
