/*
361. Bomb Enemy

Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)
Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.
*/

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
      if (grid.empty()) return 0;
      int n = grid.size(), m = grid[0].size();
      if (m == 0) return 0;

      int enemies[n][m];
      memset(enemies, 0, sizeof(enemies));

      // row by row to calculate the enemies
      for (int i = 0; i < n; i++) {
        int w_start = 0, w_end = 0;
        while (w_start < m) {
          int enemy = 0;
          while (w_end < m && grid[i][w_end] != 'W') {
            if (grid[i][w_end++] == 'E') enemy++;
          }
          // update the enemy number on zero position
          for (int j = w_start; j < w_end; j++) {
            if (grid[i][j] == '0') enemies[i][j] += enemy;
          }
          w_start = w_end + 1;   w_end = w_start;
        }
      }

      int maxEnemy = 0;

      // column by column to calculate the enemies
      for (int j = 0; j < m; j++) {
        int w_start = 0, w_end = 0;
        while (w_start < n) {
          int enemy = 0;
          while (w_end < n && grid[w_end][j] != 'W') {
            if (grid[w_end++][j] == 'E') enemy++;
          }
          for (int i = w_start; i < w_end; i++) {
            if (grid[i][j] == '0') {
              enemies[i][j] += enemy;
              maxEnemy = max(enemies[i][j], maxEnemy);
            }
          }
          w_start = w_end + 1;    w_end = w_start;
        }
      }

      return maxEnemy;
    }
};
