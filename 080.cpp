/*
080. Remove Duplicates from Sorted Array II
http://www.cnblogs.com/xinsheng/p/3504578.html

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,
Given input array nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        int len = 1;
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[len - 1]) {
                if(cnt != 2) {
                    nums[len] = nums[i];
                    cnt++;
                    len++;
                }
            } else {
                nums[len] = nums[i];
                cnt = 1;
                len++;
            }
        }
        
        return len;
    }
};
