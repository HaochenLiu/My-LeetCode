/*
075. Sort Colors
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note:
You are not suppose to use the library's sort function for this problem.
click to show follow up.
Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with an one-pass algorithm using only constant space?
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return;
        int red = 0;
        int blue = n - 1;
        while(red < n && nums[red] == 0) {
            red++;
        }

        while(blue >= 0 && nums[blue] == 2) {
            blue--;
        }

        if(red >= blue) {
            return;
        }

        for(int i = red; i <= blue; i++) {
            if(nums[i] == 0) {
                swap(nums[i], nums[red]);
                red++;
                i = max(i - 1, red);
            } else if(nums[i] == 2) {
                swap(nums[i], nums[blue]);
                blue--;
                i = min(i - 1, blue);
            }
        }
        
        return;
    }
};
