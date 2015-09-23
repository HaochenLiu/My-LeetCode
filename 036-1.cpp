/*
036. Valid Sudoku

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isValidRow(board) && isValidColumn(board) && isValidBlock(board);
    }

private:    
    bool isValidRow(vector<vector<char> > &board) {
        int count[9];
        for(int i = 0; i < 9; ++i) {
            memset(count, 0, 9 * sizeof(int));
            for(int j = 0; j < 9; ++j) {
                if(!add(count, board[i][j])) {
                    return false;
                }
            }        
        }
        return true;
    }
    
    bool isValidColumn(vector<vector<char> > &board) {
        int count[9];
        for(int i = 0; i < 9; ++i) {
            memset(count, 0, 9 * sizeof(int));
            for(int j = 0; j < 9; ++j) {
                if(!add(count, board[j][i])) {
                    return false;
                }
            }        
        }
        return true;
    }
    
    bool isValidBlock(vector<vector<char> > &board) {
        int p[9][2] = {{1, 1}, {1, 4}, {1, 7}, {4, 1}, {4, 4}, {4, 7}, {7, 1}, {7, 4}, {7, 7}};
        int d[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        int count[9];
        for(int i = 0; i < 9; ++i) {
            memset(count, 0, 9 * sizeof(int));
            add(count, board[p[i][0]][p[i][1]]);
            for(int j = 0; j < 8; ++j) {
                if(!add(count, board[p[i][0] + d[j][0]][p[i][1] + d[j][1]])) {
                    return false;
                }
            }        
        }
        return true;
    }
    
    bool add(int *count, char c) {
        if(c == '.') return true;
        return (++count[c - '1'] <= 1);
    }
};
