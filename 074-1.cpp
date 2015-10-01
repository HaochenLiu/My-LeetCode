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
Time: O(log(n+m))
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[n - 1][m- 1]) {
            return false;
        }
        int up = 0;
        int down = n - 1;
        while(up <= down) {
            int mid = up + (down - up) / 2;
            if(matrix[mid][0] == target) {
                return true;
            }
            if(matrix[mid][0] < target) {
                up = mid + 1;
            } else {
                down = mid - 1;
            }
        }
        
        int left = 1;
        int right = m - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[down][mid] == target) {
                return true;
            }
            if(matrix[down][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};
