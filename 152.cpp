/*
152. Maximum Product Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest product.
For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int res = nums[0];
        int max_temp = nums[0];
        int min_temp = nums[0];
        for(int i = 1; i < n; ++i) {
            int a = max_temp * nums[i];
            int b = min_temp * nums[i];
            max_temp = max(nums[i], max(a, b));
            min_temp = min(nums[i], min(a, b));
            res = max(res, max_temp);
        }
        return res;
    }
};
