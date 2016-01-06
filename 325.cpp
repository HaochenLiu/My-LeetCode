/*
325. Maximum Size Subarray Sum Equals k My Submissions Question

Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int ans = 0;
        if(nums.empty()) return ans;
        unordered_map<int,int> sumlen;
        int sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; ++ i){
            sum += nums[i];

            if(sum == k){
                ans = max(ans, i + 1);
            } else {
                int dif = sum - k;
                if(sumlen.find(dif) != sumlen.end()) {
                    int len = sumlen[dif];
                    ans = max(ans, i - len);
                }
            }
            if(sumlen.find(sum) == sumlen.end()) {
                sumlen[sum] = i;
            } else {
                sumlen[sum] = min(sumlen[sum], i);
            }
        }

        return ans;
    }
};
