/*
052. N-Queens II

http://www.cnblogs.com/TenosDoIt/p/3801621.html
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.
*/

/*
Time: O(n^n)
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> state(n, -1);
        res = 0;
        helper(state, 0);
        return res;
    }
    
private:
    int res;

    void helper(vector<int>& state, int row) {
        int n = state.size();
        if(row == n) {
            res++;
            return;
        }
        
        for(int col = 0; col < n; col++) {
            if(isValid(state, row, col)) {
                state[row] = col;
                helper(state, row+1);
                state[row] = -1;;
            }
        }
    }
    
    bool isValid(vector<int>& state, int row, int col) {
        for(int i = 0; i < row; i++) {
            if(state[i] == col || abs(row - i) == abs(col - state[i])) {
                return false;
            }
        }
        return true;
    }
};
