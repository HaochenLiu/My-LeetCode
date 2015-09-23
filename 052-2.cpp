/*
052. N-Queens II
http://www.cnblogs.com/TenosDoIt/p/3801621.html

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<string> record;
        record.clear();
        dfs(n, 0, 0, 0, res, record);
        return res;
    }
    
    void dfs(int n, int row, int ld, int rd, int &res, vector<string> &record) {
        if(row == (1 << n) - 1) {
            res++;
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
