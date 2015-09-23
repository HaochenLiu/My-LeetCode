/*
079. Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    int m;
    int n;
    int len;
    
    bool search(vector<vector<char> > &board, vector<vector<bool> > &flag, int row, int col, string &word, int idx) {
        if(idx == len) return true;
        if(row < 0 || row >= m) return false;
        if(col < 0 || col >= n) return false;
        if(flag[row][col]) return false;
        if(board[row][col] != word[idx]) return false;
        flag[row][col] = true;
        if(search(board, flag, row - 1, col, word, idx + 1)) return true;
        if(search(board, flag, row + 1, col, word, idx + 1)) return true;
        if(search(board, flag, row, col - 1, word, idx + 1)) return true;
        if(search(board, flag, row, col + 1, word, idx + 1)) return true;
        flag[row][col] = false;
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        if(word.length() == 0) return true;
        len = word.length();

        m = board.size();
        if(m == 0) return false;
        n = board[0].size();
        if(n == 0) return false;

        vector<bool> tmp(n, false);
        vector<vector<bool> > flag(m, tmp);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(search(board, flag, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
