/*
037. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.'.
You may assume that there will be only one unique solution.
A sudoku puzzle...
...and its solution numbers marked in red.
*/

/*
Time: O(9^e)
Space: O(1)
Extra space: O(1)
e is number of empty spaces in sudoku.
*/

class Solution {
private:
    int N;

    bool isValid(vector<vector<char>>& board, int x, int y) {
        //check line
        for(int j = 0; j < N; j++) {
            if(j != y && board[x][j] == board[x][y]) {
                return false;
            }
        }
        
        //check colume
        for(int i = 0; i < N; i++) {
            if(i != x && board[i][y] == board[x][y]) {
                return false;
            }
        }
        
        //check block
        for(int i = x / 3 * 3; i < x / 3 * 3 + 3; i++) {
            for(int j = y / 3 * 3; j < y / 3 * 3 + 3; j++) {
                if((i != x || j != y) && board[i][j] == board[x][y]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solveSudokuRecur(vector<vector<char>>& board) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] != '.') {
                    continue;
                }
                for(int k = 1; k <= 9; k++) {
                    board[i][j] = k + '0';
                    if(isValid(board, i, j)) {
                        if(solveSudokuRecur(board)) {
                            return true;
                        }
                    }
                }
                board[i][j] = '.';
                return false;
            }
        }

        return true;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() != 9 || board[0].size() != 9) return;
        N = board.size();
        solveSudokuRecur(board);
        return;
    }
};
