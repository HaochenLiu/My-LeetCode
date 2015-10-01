/*
123. Best Time to Buy and Sell Stock III

http://www.cnblogs.com/x1957/archive/2013/08/26/3282471.html
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

/*
Time: O(n)
Space: O(n)
Extra space: O(n)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        vector<int> minValLeft(n, 0);
        vector<int> maxValLeft(n, 0);
        vector<int> minValRight(n, 0);
        vector<int> maxValRight(n, 0);
        vector<int> profitLeft(n, 0);
        vector<int> profitRight(n, 0);
        minValLeft[0] = prices[0];
        maxValLeft[0] = prices[0];
        minValRight[n - 1] = prices[n - 1];
        maxValRight[n - 1] = prices[n - 1];
        profitLeft[0] = 0;
        profitRight[n - 1] = 0;

        for(int i = 1; i < n; i++) {
            minValLeft[i] = min(minValLeft[i - 1], prices[i]);
            maxValLeft[i] = max(maxValLeft[i - 1], prices[i]);
            profitLeft[i] = max(profitLeft[i - 1], prices[i] - minValLeft[i - 1]);
        }

        for(int i = n - 2; i >= 0; i--) {
            minValRight[i] = min(minValRight[i + 1], prices[i]);
            maxValRight[i] = max(maxValRight[i + 1], prices[i]);
            profitRight[i] = max(profitRight[i + 1], maxValRight[i + 1] - prices[i]);
        }
        
        int res = 0;
        for(int i = 0; i < n - 1; i++) {
            res = max(res, maxValRight[i + 1] - minValLeft[i]);
        }
        
        for(int i = 0; i < n - 1; i++) {
            res = max(res, profitLeft[i] + profitRight[i + 1]);
        }

        return res;
    }
};
