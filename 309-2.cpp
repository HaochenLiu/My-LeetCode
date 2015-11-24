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
Time: O(n^2)
Space: O(n)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        vector<int> local(n, 0);
        vector<int> global(n, 0);
        local[1] = max(local[1], prices[1] - prices[0]);
        global[1] = max(global[0], local[1]);

        for(int i = 2; i < n; i++) {
            local[i] = max(local[i - 1], prices[i] - prices[0]);
            local[i] = max(local[i], prices[i] - prices[1]);
            for(int j = 2; j < i; j++) {
                local[i] = max(local[i], local[j - 2] + prices[i] - prices[j]);
            }
            global[i] = max(global[i - 1], local[i]);
        }
        
        return global[n - 1];
    }
};
