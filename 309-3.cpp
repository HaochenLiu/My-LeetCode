

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        
        vector<int> local(n, 0);
        vector<int> global(n, 0);
        
        local[1] = prices[1] - prices[0];
        global[1] = max(global[0], local[1]);
        local[2] = prices[2] - min(prices[0], prices[1]);
        global[2] = max(global[1], local[2]);
        
        for(int i = 3; i < n; i++) {
            int diff = prices[i] - prices[i - 1];
            local[i] = max(local[i - 1], global[i - 3]) + diff;
            global[i] = max(global[i - 1], local[i]);
        }
        
        return global[n - 1];
    }
};
