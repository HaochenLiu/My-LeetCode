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
One pass
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 3) return 0;
        int res = 0;
        int leftIdx = 0;
        int leftVal = height[leftIdx];
        int rightIdx = n - 1;
        int rightVal = height[rightIdx];
        while(leftIdx < rightIdx) {
            while(leftIdx < rightIdx && leftVal <= height[leftIdx + 1]) {
                leftIdx++;
                leftVal = height[leftIdx];
            }
            while(rightIdx > leftIdx && rightVal <= height[rightIdx - 1]) {
                rightIdx--;
                rightVal = height[rightIdx];
            }
            if(leftIdx >= rightIdx) {
                break;
            }
            if(leftVal < rightVal) {
                leftIdx++;
                res += (leftVal - height[leftIdx]);
            } else {
                rightIdx--;
                res += (rightVal - height[rightIdx]);
            }
        }
        return res;
    }
};
