/*
036. Valid Sudoku

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
A partially filled sudoku which is valid.
Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
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

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() != 9 || board[0].size() != 9) return false;
        N = board.size();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                if(!isValid(board, i, j)) {
                    return false;
                }
            }
        }

        return true;
    }
};
