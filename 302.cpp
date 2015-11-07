/*
302. Smallest Rectangle Enclosing Black Pixels

An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6.
*/

class Solution {
private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool inBound(int x, int y, int n, int m) {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }

public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if(image.empty() || image[0].empty()) return 0;
        int n = image.size();
        int m = image[0].size();
        int up = x;
        int down = x;
        int left = y;
        int right = y;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int ox = p.first;
            int oy = p.second;
            for(int i = 0; i < 4; i++) {
                int nx = ox + dx[i];
                int ny = oy + dy[i];
                if(!inBound(nx, ny, n, m)) continue;
                if(image[nx][ny] == '0') continue;
                if(visited[nx][ny]) continue;
                visited[nx][ny] = true;
                up = min(up, nx);
                down = max(down, nx);
                left = min(left, ny);
                right = max(right, ny);
                q.push(make_pair(nx, ny));
            }
        }
        
        return (down - up + 1) * (right - left + 1);
    }
};
