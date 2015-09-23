/*
037. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

A sudoku puzzle...

...and its solution numbers marked in red.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board, int row, int col) {
        for(int i = 0; i < 9; i++) {
            if(i != row && board[row][col] == board[i][col]) {
                return false;
            }
        }
        
        for(int i = 0; i < 9; i++) {
            if(i != col && board[row][col] == board[row][i]) {
                return false;
            }
        }
        
        for(int i = row / 3 * 3; i < row / 3 * 3 + 3; i++) {
            for(int j = col /3 * 3; j < col /3 * 3 + 3; j++) {
                if(i != row && j != col && board[row][col] == board[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char> > &board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(int k = 1; k <= 9; k++) {
                        board[i][j] = '0' + k;
                        if(isValidSudoku(board, i, j)) {
                            if(solve(board)) {
                                return true;
                            }
                        }
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char> > &board) {
        solve(board);
        return;
    }
};
