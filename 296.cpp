/*
296. Best Meeting Point

A group of people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

Hint:

Try to solve it in one dimension first. How can this solution apply to the two dimension case?
*/

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row;
        vector<int> col;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        n = row.size();
        if(n < 2) {
            return 0;
        }
        
        sort(row.begin(), row.end());
        sort(col.begin(), col.end());

        int r = row[n / 2];
        int c = col[n / 2];
        int res = 0;

        for(int i = 0; i < n; i++) {
            res += abs(row[i] - r);
            res += abs(col[i] - c);
        }

        return res;
    }
};
