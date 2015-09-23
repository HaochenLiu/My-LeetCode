/*
279. Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    int numSquares(int n) {
        if(n <= 3) return n;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i <= n; i++) {
            int minVal = INT_MAX;
            for(int j = 1; j <= i / j; j++) {
                minVal = min(minVal, 1 + dp[i - j * j]);
            }
            dp[i] = minVal;
        }
        return dp[n];
    }
};
