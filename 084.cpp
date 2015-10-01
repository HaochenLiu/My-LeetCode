/*
084. Largest Rectangle in Histogram
http://blog.csdn.net/doc_sgl/article/details/11805519
O(n)

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

/*
Time: O(n)
Space: O(n)
Extra space: O(n)
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0); //至关重要，保证最后stk一定空。
        stack<int> stk;
        int i = 0;
        int maxArea = 0;
        while(i < height.size()) {
            if(stk.empty() || height[stk.top()] <= height[i]) {
                stk.push(i++);
            } else {
                int t = stk.top();
                stk.pop();
                maxArea = max(maxArea, height[t] * (stk.empty()? i: i - stk.top() - 1));
            }
        }
        
        return maxArea;
    }
};
