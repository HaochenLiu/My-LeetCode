/*
309. Best Time to Buy and Sell Stock with Cooldown

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
Credits:
Special thanks to @peisi for adding this problem and creating all test cases.
*/

/*
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;

        vector<int> full(n, 0);
        vector<int> empty(n, 0);
        vector<int> sell(n, 0);
        
        full[0] = -prices[0];
        for(int i = 1; i < prices.size(); i++) {
            full[i] = max(full[i - 1], empty[i - 1] - prices[i]);
            sell[i] = full[i - 1] + prices[i];
            empty[i] = max(empty[i - 1], sell[i - 1]);
        }

        return max(empty[prices.size() - 1], sell[prices.size() - 1]);
    }
};
