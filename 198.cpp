/*
198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
*/

class Solution {
public:
    int rob(vector<int> &num) {
        int n = num.size();
        if(n == 0) {
            return 0;
        } else if(n == 1) {
            return num[0];
        } else if(n == 2) {
            return max(num[0], num[1]);
        } else {
            vector<int> dp(n, 0);
            dp[n - 1] = num[n - 1];
            dp[n - 2] = max(num[n - 1], num[n - 2]);
            for(int i = n - 3; i >= 0; i--) {
                dp[i] = max(num[i] + dp[i + 2], dp[i + 1]);
            }
            return dp[0];
        }
    }
};
