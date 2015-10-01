/*
059. Spiral Matrix II

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

/*
Time: O(n^2)
Space: O(n^2)
Extra space: O(1)
*/

class Solution {
public:
    int step[4][2];
    int canUse[100][100];
    
    void dfs(vector<vector<int> > &res, int dep, int maxDep, int dir, int x, int y) {
        if(dep == maxDep) return;
        for(int i = 0; i < 4; ++i) {
            int j = (dir + i) % 4;
            int tx = x + step[j][0];
            int ty = y + step[j][1];
            if(tx >= 0 && tx < res.size() && ty >= 0 && ty < res[0].size() && canUse[tx][ty]) {
                res[tx][ty] = dep + 1;
                canUse[tx][ty] = false;
                dfs(res, dep + 1, maxDep, j, tx, ty);
            }
        }
    }
    
    vector<vector<int> > generateMatrix(int n) {
        if(n == 0) {
            vector<vector<int> > res;
            res.clear();
            return res;
        }

        step[0][0] = 0;
        step[0][1] = 1;
        step[1][0] = 1;
        step[1][1] = 0;
        step[2][0] = 0;
        step[2][1] = -1;
        step[3][0] = -1;
        step[3][1] = 0;
        vector<vector<int> > res(n, vector<int>(n, 0));
        memset(canUse, true, sizeof(canUse));
        dfs(res, 0, n * n, 0, 0, -1);
        return res;
    }
};
