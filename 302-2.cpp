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

    bool emptyRow(vector<vector<char>>& image, int row) {
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < m; i++) {
            if(image[row][i] != '0') {
                return false;
            }
        }
        return true;
    }
    
    bool emptyCol(vector<vector<char>>& image, int col) {
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < n; i++) {
            if(image[i][col] != '0') {
                return false;
            }
        }
        return true;
    }
    
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if(image.empty() || image[0].empty()) return 0;
        int n = image.size();
        int m = image[0].size();
        int up;
        int down;
        int left;
        int right;

        int b1 = 0;
        int b2 = x;
        while(b1 < b2) {
            int mid = b1 + (b2 - b1) / 2;
            if(emptyRow(image, mid)) {
                b1 = mid + 1;
            } else {
                b2 = mid;
            }
        }
        up = b1;

        b1 = x;
        b2 = n - 1;
        while(b1 < b2) {
            int mid = b1 + (b2 - b1 + 1) / 2;
            if(emptyRow(image, mid)) {
                b2 = mid - 1;
            } else {
                b1 = mid;
            }
        }
        down = b1;

        b1 = 0;
        b2 = y;
        while(b1 < b2) {
            int mid = b1 + (b2 - b1) / 2;
            if(emptyCol(image, mid)) {
                b1 = mid + 1;
            } else {
                b2 = mid;
            }
        }
        left = b1;

        b1 = y;
        b2 = m - 1;
        while(b1 < b2) {
            int mid = b1 + (b2 - b1 + 1) / 2;
            if(emptyCol(image, mid)) {
                b2 = mid - 1;
            } else {
                b1 = mid;
            }
        }
        right = b1;

        return (down - up + 1) * (right - left + 1);
    }
};
