/*
209. Minimum Size Subarray Sum

Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
click to show more practice.
More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int minlen = INT_MAX;
        int sum = 0;
        int left = 0;
        int right = -1;
        while(right < len) {
            while(sum < s && right < len) {
                sum += nums[++right];
            }
            if(sum >= s) {
                minlen = minlen < right-left+1 ? minlen : right-left+1;
                sum -= nums[left++];
            }
        }
        return minlen > len ? 0 : minlen;
    }
};
