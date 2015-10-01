/*
085. Maximal Rectangle

http://www.cnblogs.com/remlostime/archive/2012/11/12/2766566.html
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

/*
Time: O(nm^2)
Space: O(nm)
Extra space: O(nm)
Assume n >= m
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int N = matrix.size(), M = matrix[0].size();
        int res = 0;
        pair<int, int> dp[N][M];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (matrix[i][j] == '0') continue;
                int x = j == 0 ? 1 : dp[i][j - 1].first + 1;
                int y = i == 0 ? 1 : dp[i - 1][j].second + 1;
                dp[i][j] = make_pair(x, y);
                int minHeight = y;
                for (int k = j; k > (j - x); k--) {
                    minHeight = min(minHeight, dp[i][k].second);
                    res = max(res, minHeight * (j - k + 1));
                }
            }
        }
        return res;
    }
};
