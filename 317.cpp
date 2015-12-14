/*
317. Shortest Distance from All Buildings

You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You are given a 2D grid of values 0, 1 or 2, where:

    Each 0 marks an empty land which you can pass by freely.
    Each 1 marks a building which you cannot pass through.
    Each 2 marks an obstacle which you cannot pass through.

The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/

#define MP make_pair
#define MT make_tuple

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int N = grid.size();
        int M = grid[0].size();
        int checkcnt = 0;
        vector<vector<int> > dis(N, vector<int>(M, 0));
        vector<vector<int> > cnt(N, vector<int>(M, 0));
        int ans = INT_MAX;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 1) {
                    checkcnt++;
                    queue<tuple<int, int, int> > Q;
                    map<pair<int, int>, bool> vis;
                    vis[MP(i, j)] = true;
                    Q.push(MT(i, j, 0));
                    while (!Q.empty()) {
                        int cx = get<0>(Q.front());
                        int cy = get<1>(Q.front());
                        int cs = get<2>(Q.front());
                        Q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nx = cx + dx[k];
                            int ny = cy + dy[k];
                            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                            if (vis[MP(nx, ny)]) continue;
                            if (grid[nx][ny] != 0) continue;
                            vis[MP(nx, ny)] = true;
                            cnt[nx][ny]++;
                            Q.push(MT(nx, ny, cs + 1));
                            dis[nx][ny] += cs + 1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 0 && cnt[i][j] == checkcnt) {
                    ans = min(ans, dis[i][j]);
                }
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
