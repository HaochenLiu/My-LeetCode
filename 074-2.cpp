/*
074. Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.
*/

/*
Time: O(n+m)
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int i = 0;
        int j = matrix[0].size() - 1;
        
        while (i < matrix.size() && j >= 0) {
            if (target == matrix[i][j]) {
                return true;
            } else if (target < matrix[i][j]) {
                j--;
            } else {
                i++;
            }
        }
        
        return false;
    }
};
