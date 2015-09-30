/*
048. Rotate Image

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

/*
Time: O(n^2)
Space: O(n^2)
Extra space: O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int size = matrix.size();
        for(int i = 0; i < size  / 2; ++i) {
            for(int j = 0; j < (size + 1) / 2; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[size - 1 - j][i];
                matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j];
                matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
                matrix[j][size - 1 - i]= tmp;;
            }
        }
    }
};
