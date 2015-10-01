/*
119. Pascal's Triangle II

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

/*
Time: O(n^2)
Space: O(n)
Extra space: O(n)
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > f(2, vector<int>(rowIndex + 1 , 0));
        int mark = 0;
        f[mark][0] = 1;
        f[mark][1] = 1;
        mark = (mark + 1) % 2;
        for(int i = 1; i < rowIndex; ++i) {
            f[mark][0] = 1;
            f[mark][i + 1] = 1;
            for(int j = 1 ; j <= i ; ++j){
                f[mark][j] = f[(mark + 1) % 2][j - 1] + f[(mark + 1) % 2][j];
            }
            mark = (mark + 1) % 2;
        }
        return f[(mark+1) %2];
    }
};
