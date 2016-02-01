/*
329. Longest Increasing Path in a Matrix

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        // dp[i][j] = length of longest increasing path that STARTS from (i,j)
        vector<vector<int>> dp(m, vector<int>(n, 1));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maxLen = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // dfs returns maximum length of the increasing path that reaches (i, j)
                int curLen = dfs(matrix, i, j, visited, dp);
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
    }
    
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    int dfs(vector<vector<int>> &matrix, int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &dp) {
        //if (dp[x][y] != 0) return dp[x][y];
        if (visited[x][y]) return dp[x][y];
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (inbound(matrix, nx, ny) && matrix[nx][ny] > matrix[x][y]) {
                // route (x, y) to go through (nx, ny) to get a longer path
                dp[x][y] = max(dp[x][y], 1 + dfs(matrix, nx, ny, visited, dp));
            }
        }
        visited[x][y] = true;
        return dp[x][y];
    }
    
    bool inbound(vector<vector<int>> &matrix, int x, int y) {
        return (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size()); 
    }
};
