/*
300. Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        vector<int> v;
        v.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            if(nums[i] > v.back()) {
                v.push_back(nums[i]);
            } else {
                int idx = upper_bound(v.begin(), v.end(), nums[i]) - v.begin();
                if(idx == 0 || v[idx - 1] != nums[i]) {
                    v[idx] = nums[i];
                }
            }
        }

        return v.size();
    }
};
