/*
121. Best Time to Buy and Sell Stock
http://www.cnblogs.com/remlostime/archive/2012/11/06/2757434.html

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

/*
Time: O(n)
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) return 0;
            
        int maxPrice = prices[prices.size() - 1];
        int ans = 0;
        for(int i = prices.size() - 1; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            ans = max(ans, maxPrice - prices[i]);
        }
        
        return ans;
    }
};
