/*
305. Number of Islands II

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

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of the positions?
*/

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if(n == 0 || m == 0) return res;
        vector<int> father(n * m, -1);
        vector<int> rank(n * m, 0);
        int sz = positions.size();
        for(int i = 0; i < sz; i++) {
            int x = positions[i].first;
            int y = positions[i].second;
            int t = x * n + y;
            int ft = find(father, t);
            if(i == 0) {
                res.push_back(1);
                continue;
            }

            int cnt = res.back() + 1;
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                int nt = nx * n + ny;
                if(!inBound(nx, ny, m, n)) continue;
                if(father[nt] == -1) continue;
                ft = find(father, t);
                int fnt = find(father, nt);
                if(ft != fnt) {
                    cnt--;
                    if(rank[ft] < rank[fnt]) {
                        father[ft] = fnt;
                    } else if(rank[fnt] < rank[ft]) {
                        father[fnt] = ft;
                    } else {
                        father[ft] = fnt;
                        rank[fnt]++;
                    }
                }
            }
            res.push_back(cnt);
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

        return r;
    }

    bool inBound(int x, int y, int m, int n) {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }
};
