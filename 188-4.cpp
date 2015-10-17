/*
188. Best Time to Buy and Sell Stock IV

Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

http://blog.csdn.net/foreverling/article/details/43911309
*/

/*
Time： O(n^2 * k)
Space: O(nk)
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k <= 0 || n < 2) return 0;
        vector<int> minValLeft(n, 0);

        if(k >= n / 2) {
            int res = 0;
            for(int i = 0; i < n - 1; i++) {
                res += max(0, prices[i + 1] - prices[i]);
            }
            return res;
        }

        k = min(k, n / 2);
        vector<vector<int>> dp(n, vector<int>(k, 0));
        
        minValLeft[0] = prices[0];
        for(int j = 0; j < k; j++) {
            dp[0][j] = 0;
        }
        int res = 0;

        for(int i = 1; i < n; i++) {
            minValLeft[i] = min(minValLeft[i - 1], prices[i]);
            dp[i][0] = max(dp[i - 1][0], prices[i] - minValLeft[i - 1]);
            res = max(res, dp[i][0]);
        }

        for(int j = 1; j < k; j++) {
            for(int i = 1; i < n; i++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if(prices[i] > prices[i - 1]) {
                    int minVal = prices[i - 1];
                    if(i >= 2) {
                        dp[i][j] = max(dp[i][j], dp[i - 2][j - 1] + (prices[i] - minVal));
                    }
                    for(int l = i - 2; l > 0; l--) {
                        minVal = min(minVal, prices[l]);
                        dp[i][j] = max(dp[i][j], dp[l - 1][j - 1] + (prices[i] - minVal));
                        if(minVal == minValLeft[i - 1]) {
                            break;
                        }
                    }
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
