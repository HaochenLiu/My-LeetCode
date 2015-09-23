/*
051. N-Queens

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
private:
    bool isValid(vector<string>& board, int x, int y) {
        for(int i = 0; i < x; ++i) {
            if(board[i][y] == 'Q') {
                return false;
            }
        }

        for(int i = 0; i < x; ++i) {
            int j = x + y - i;
            if(j >= 0 && j < board.size() && board[i][j] == 'Q') {
                return false;
            }
            j = i - x + y;
            if(j >= 0 && j < board.size() && board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void solve(vector<vector<string>>& res, vector<string>& board, int x) {
        if(x == board.size()) {
            res.push_back(board);
            return;
        }
        for(int y = 0; y < board.size(); ++y) {
            board[x][y] = 'Q';
            if(isValid(board, x, y)) {
                solve(res, board, x + 1);
            }
            board[x][y] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res;
        string str(n, '.');
        vector<string> board(n, str);
        solve(res, board, 0);
        return res;
    }
};
