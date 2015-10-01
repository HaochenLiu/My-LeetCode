/*
120. Triangle

http://www.cnblogs.com/remlostime/archive/2012/11/15/2772242.html
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

/*
Time: O(n^2)
Space: O(n)
Extra space: O(n)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0) return 0;
        int n = triangle.size();
        int res = 0;
        vector<int> tmp(n, 0);
        for(int i = triangle.size() - 1; i >= 0; --i) {
            for(int j = 0; j <= i; ++j) {
                if(i == triangle.size() - 1) {
                    tmp[j] = triangle[i][j];
                } else {
                    tmp[j] = triangle[i][j] + min(tmp[j], tmp[j + 1]);
                }
            }
        }
        return tmp[0];
    }
};
