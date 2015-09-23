/*
073. Set Matrix Zeroes
http://www.cnblogs.com/xinsheng/p/3505299.html

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row0 = 1, column0 = 1;
        int m = matrix.size();
        if(m <= 0) return;
        
        int n = matrix[0].size();
        if(n <= 0) return;
 
        for(int i = 0; i < n; ++i) {
            if(matrix[0][i] == 0) {
                row0 = 0;
                break;
            }
        }
        
        for(int j = 0; j < m; ++j) {
            if(matrix[j][0] == 0) {
                column0 = 0;
                break;
            }
        }
 
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
 
        for(int i = 1; i < n; ++i) {
            if(matrix[0][i] == 0) {
                for(int j = 1; j < m; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; ++i) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
 
        if(row0 == 0) {
            for(int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }
        
        if(column0 == 0) {
            for(int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
