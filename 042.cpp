/*
042. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

/*
Time: O(n)
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 2) return 0;

        int res = 0;
        int maxValue = -1;
        int maxIndex = -1;

        for(int i = 0; i < n; i++) {
            if(height[i] > maxValue) {
                maxValue = height[i];
                maxIndex = i;
            }
        }
        
        int tmp = height[0];
        for(int i = 1; i < maxIndex; i++) {
            tmp = max(tmp, height[i]);
            res += (tmp - height[i]);
        }
        
        tmp = height[n - 1];
        for(int i = n - 2; i > maxIndex; i--) {
            tmp = max(tmp, height[i]);
            res += (tmp - height[i]);
        }
        return res;
    }
};
