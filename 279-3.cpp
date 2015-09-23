/*
279. Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
private:
    int getNum(vector<int>& dp, int n) {
        if(n == 0) return 0;
        if(dp[n] != 0) return dp[n];

        int res = INT_MAX;
        for(int i = 1; i <= n / i; i++) {
            res = min(res, getNum(dp, n - i * i) + 1);
            if(res == 2) {
                dp[n] = 2;
                return 2;
            }
        }

        dp[n] = res;
        return res;
    }

public:
    int numSquares(int n) {
        if(n <= 3) return n;

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 2; i <= n / i; i++) {
            dp[i * i] = 1;
        }

        return getNum(dp, n);
    }
};
