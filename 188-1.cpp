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
Time： O(nk)
Space: O(nk)
*/

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if(n < 2 || k == 0) return 0;
        if(k > n / 2) return solveMaxProfit(prices);
        k = min(k, n / 2);
        vector<vector<int>> mustSell(n, vector<int>(k + 1, 0));
        vector<vector<int>> globalBest(n, vector<int>(k + 1, 0));

        for (int i = 1; i < n; i++) {
            int gain = prices[i] - prices[i - 1];
            for (int j = 1; j <= k; j++) {
                mustSell[i][j] = max(globalBest[i - 1][j - 1], mustSell[i - 1][j]) + gain;
                globalBest[i][j] = max(globalBest[i - 1][j], mustSell[i][j]);
            }
        }

        return globalBest[n - 1][k];
    }

    int solveMaxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};
