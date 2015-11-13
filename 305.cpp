/*
Number of Islands II

A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0

Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0

Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0

Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0

Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0

We return the result as an array: [1, 1, 2, 3]

Update: (2015/11/13)
If you are using Java, the parameter List<int[]> positions had been changed to int[][] positions. Please click on the reload button above the code editor
to reset the code definition.
*/

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if(n == 0 || m == 0) return res;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<int> father(n * m, -1);
        int sz = positions.size();
        for(int i = 0; i < sz; i++) {
            int x = positions[i].first;
            int y = positions[i].second;
            grid[x][y] = 1;
            int t = x * n + y;
            int ft = find(father, t);
            if(i == 0) {
                res.push_back(1);
                continue;
            }
            unordered_set<int> s;
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                int nt = nx * n + ny;
                if(!inBound(nx, ny, m, n)) continue;
                if(grid[nx][ny] == 0) continue;
                s.insert(find(father, nt));
            }
            res.push_back(res.back() + 1 - s.size());

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                int nt = nx * n + ny;
                if(!inBound(nx, ny, m, n)) continue;
                if(grid[nx][ny] == 0) continue;
                ft = find(father, t);
                int fnt = find(father, nt);
                father[ft] = min(ft, fnt);
                father[fnt] = min(ft, fnt);
            }
        }

        return res;
    }
    
private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int find(vector<int>& father, int a) {
        if(father[a] == -1) {
            father[a] = a;
            return a;
        }
        
        int r = a;
        while(father[r] != r) {
            r = father[r];
        }
        
        int f = a;
        int p;
        while(f != r) {
            p = father[f];
            father[f] = r;
            f = p;
        }

        return r;
    }

    bool inBound(int x, int y, int m, int n) {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }
};
