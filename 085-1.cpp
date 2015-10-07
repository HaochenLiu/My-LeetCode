/*
085. Maximal Rectangle

http://www.cnblogs.com/remlostime/archive/2012/11/12/2766566.html
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

/*
Time: O(nm)
Space: O(m)
Extra space: O(m)
Assume n >= m
*/

class Solution {
private:
    int largestRectangleArea(vector<int> height) {
        height.push_back(0);
        stack<int> stk;
        int i = 0;
        int maxArea = 0;
        while(i < height.size()) {
            if(stk.empty() || height[stk.top()] <= height[i]) {
                stk.push(i++);
            } else {
                int t = stk.top();
                stk.pop();
                maxArea = max(maxArea, height[t] * (stk.empty() ? i: i - stk.top() - 1));
            }
        }
        
        return maxArea;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> h1(m, 0);
        vector<int> h2(m, 0);
        int res = 0;
        for(int i = 0; i < n; i++) {
            if((i & 1) == 0) {
                for(int j = 0; j < m; j++) {
                    if(matrix[i][j] == '1') {
                        h1[j] = 1 + h2[j];
                    } else {
                        h1[j] = 0;
                    }
                }
                res = max(res, largestRectangleArea(h1));
            } else {
                for(int j = 0; j < m; j++) {
                    if(matrix[i][j] == '1') {
                        h2[j] = 1 + h1[j];
                    } else {
                        h2[j] = 0;
                    }
                }
                res = max(res, largestRectangleArea(h2));
            }
        }
        return res;
    }
};
