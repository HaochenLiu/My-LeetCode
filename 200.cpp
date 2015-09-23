/*
200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example 1:
11110
11010
11000
00000
Answer: 1
Example 2:
11000
11000
00100
00011
Answer: 3
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

class Solution {
public:
    int n;
    int m;
    void solve(vector<vector<char> > &grid, vector<vector<bool> > &flag, int row, int col) {
        if(row < 0 || row >= n) return;
        if(col < 0 || col >= m) return;

        if(grid[row][col] == '0' || flag[row][col]) {
            return;
        }

        flag[row][col] = true;
        solve(grid, flag, row, col - 1);
        solve(grid, flag, row, col + 1);
        solve(grid, flag, row - 1, col);
        solve(grid, flag, row + 1, col);
        return;
    }
    
    int numIslands(vector<vector<char>> &grid) {
        n = grid.size();
        if(n == 0) return 0;
        m = grid[0].size();
        if(m == 0) return 0;
        
        int res = 0;
        vector<bool> row(m, false);
        vector<vector<bool> > flag(n, row);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '0' || flag[i][j]) {
                    continue;
                }

                res++;
                solve(grid, flag, i, j);
            }
        }
        return res;
    }
};
