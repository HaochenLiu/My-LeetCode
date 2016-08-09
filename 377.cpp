/*
377. Combination Sum IV

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int f[target + 1] = {0};
        f[0] = 1;
        for (int i = 0; i <= target; ++i) {
            if (f[i] == 0) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                int t = i + nums[j];
                if (t <= target) {
                    f[t] += f[i];
                }
            }
        }
        return f[target];
    }
};
