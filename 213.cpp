/*
213. House Robber II

Note: This is an extension of House Robber.
After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) {
            return 0;
        } else if(len == 1) {
            return nums[0];
        } else if(len == 2) {
            return max(nums[0], nums[1]);
        }

        int d[len];
        d[0] = nums[0];
        d[1] = max(nums[0], nums[1]);
        for(int i = 2; i < len; i++){
            d[i] = max(d[i - 1], nums[i] + d[i - 2]);
        }
        if(d[len - 1] == d[len - 2]){
            return d[len - 1];
        }

        int dr[len];
        dr[len - 1]=nums[len - 1];
        dr[len - 2]=max(nums[len - 1], nums[len - 2]);
        for(int i = len - 3; i >= 0; i--){
            dr[i] = max(dr[i + 1], nums[i] + dr[i + 2]);
        }
        return max(dr[1], d[len - 2]);
    }
};
