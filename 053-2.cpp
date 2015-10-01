/*
053. Maximum Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

/*
Time: O(nlogn)
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int res = nums[0];
        int n = nums.size();
        vector<int> left(nums.begin(), nums.begin() + n / 2);
        vector<int> right(nums.begin() + n / 2, nums.end());
        res = max(res, maxSubArray(left));
        res = max(res, maxSubArray(right));
        int maxLeft = nums[n / 2 - 1];
        int maxRight = nums[n / 2];
        int tmpLeft = 0;
        int tmpRight = 0;
        for(int i = n / 2 - 1; i >= 0; i--) {
            tmpLeft += nums[i];
            maxLeft = max(maxLeft , tmpLeft);
        }
        for(int i = n / 2; i < n; i++) {
            tmpRight += nums[i];
            maxRight = max(maxRight , tmpRight);
        }
        res = max(res, maxLeft + maxRight);
        return res;
    }
};
