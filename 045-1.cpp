/*
045. Jump Game II
http://blog.csdn.net/lanxu_yy/article/details/11714231

Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

/*
Time: O(n^2)
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int step = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[0] == 1) {
                nums.erase(nums.begin());
                step++;
            } else {
                break;
            }
        }
        
        int n = nums.size();
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
        return step;
    }
};
