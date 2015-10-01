/*
053. Maximum Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

/*
Time: O(n)
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int res = nums[0];
        int sum = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            sum = max(sum + nums[i], nums[i]);
            res = max(res, sum);
        }
        return res;
    }
};
