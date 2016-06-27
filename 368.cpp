/*
368. Largest Divisible Subset

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]
Credits:
Special thanks to @Stomach_ache for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        if (!n) return ret;
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> dp[n];
        int maxi = 0;
        dp[maxi].push_back(make_pair(nums[0], -1));
        for (int i = 1; i < n; ++i) {
            int j = maxi;
            while (j >= 0) {
                for (int id = 0; id < dp[j].size(); ++id) {
                    if (nums[i] % dp[j][id].first == 0) {
                        dp[j + 1].emplace_back(nums[i], id);
                        maxi = max(maxi, j + 1);
                        goto out_of_while;
                    }
                }
                --j;
            }
            dp[j + 1].emplace_back(nums[i], -1);
            out_of_while:;
        }
        int i = maxi, id = 0;
        while (i >= 0) {
            ret.push_back(dp[i][id].first);
            id = dp[i][id].second;
            --i;
        }
        return ret;
    }
};
