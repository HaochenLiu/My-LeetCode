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

/*
Time: O(n^n)
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> record;
        res.clear();
        record.clear();
        dfs(n, 0, 0, 0, res, record);
        return res;
    }
    
    void dfs(int n, int row, int ld, int rd, vector<vector<string> > & res, vector<string> &record) {
        if(row == (1 << n) - 1) {
            res.push_back(record);
            return;
        }

        int avail = ~(row | ld | rd);
        for(int i = n - 1; i >= 0; --i) {
            int t = 1 << i;
            if(avail & t) {
                string s(n, '.');
                s[i] = 'Q';
                record.push_back(s);
                dfs(n, row | t, (ld | t) << 1, (rd | t) >> 1, res, record);
                record.pop_back();
            }
        }
    }
};
