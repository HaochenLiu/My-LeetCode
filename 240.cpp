/*
240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,
Consider the following matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]


Given target = 5, return true.
Given target = 20, return false.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m<=0){
            return false;
        }
        int n = matrix[0].size();
        if(n<=0){
            return false;
        }
        return searchMatrixHelper(matrix, 0, m-1, 0, n-1, target);
    }
    
    bool searchMatrixHelper(vector<vector<int>>& matrix, int startM, int endM, int startN, int endN, int target){
        if(startM > endM || startN > endN){
            return false;
        }
        int middleM = (startM + endM) / 2;
        int middleN = (startN + endN) / 2;
        if(matrix[middleM][middleN]==target){
            return true;
        }else if(matrix[middleM][middleN]<target){
            return  searchMatrixHelper(matrix, startM, endM, middleN + 1, endN, target) ||
                    searchMatrixHelper(matrix, middleM + 1, endM, startN, middleN, target);
        }else{
            return  searchMatrixHelper(matrix, startM, middleM - 1, startN, endN, target) ||
                    searchMatrixHelper(matrix, middleM, endM, startN, middleN - 1, target);
        }
    }
};
