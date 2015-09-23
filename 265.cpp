/*
265. Paint House II

There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
Note:
All costs are positive integers.
Follow up:
Could you solve it in O(nk) runtime?
*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size() == 0 || costs[0].size() == 0) return 0;
        int n = costs.size();
        int k = costs[0].size();

        if(n == 0 || k == 0) return 0;
        if(k == 1) return costs[0][0];

        int dp[n][k];

        for(int j = 0; j < k; j++) {
            dp[0][j] = costs[0][j];
        }

        for(int i = 0; i < n - 1; i++) {
            int minIndex1 = 0;
            int minIndex2 = 1;
            if(dp[i][0] > dp[i][1]) {
                minIndex1 = 1;
                minIndex2 = 0;
            }

            for(int j = 2; j < k; j++) {
                if(dp[i][j] >= dp[i][minIndex2]) {
                    continue;
                } else if(dp[i][j] <= dp[i][minIndex1]) {
                    minIndex2 = minIndex1;
                    minIndex1 = j;
                } else {
                    minIndex2 = j;
                }
            }

            for(int j = 0; j < k; j++) {
                if(j == minIndex1) {
                    dp[i + 1][j] = dp[i][minIndex2] + costs[i + 1][j];
                } else {
                    dp[i + 1][j] = dp[i][minIndex1] + costs[i + 1][j];
                }
            }
        }
        
        int res = INT_MAX;
        for(int j = 0; j < k; j++) {
            res = min(res, dp[n - 1][j]);
        }

        return res;
    }
};
