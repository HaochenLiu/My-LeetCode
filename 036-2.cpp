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
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        const int N = 9;
        int col[N];
        int box[N];
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));
        for(int i = 0; i < N; ++i) {
            int row = 0;
            for(int j = 0; j < N; ++j) {
                if(board[i][j] == '.') continue;
                int bit = 1 << (board[i][j] - '1');
                int box_index = i / 3 * 3 + j / 3;
                if((row & bit) || (col[j] & bit) || (box[box_index] & bit)) return false;
                row |= bit;
                col[j] |= bit;
                box[box_index] |= bit;
            }
        }
        return true;
    }
};
