/*
041. First Missing Positive
http://blog.csdn.net/nanjunxiao/article/details/12973173

Given an unsorted integer array, find the first missing positive integer.
For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.
Your algorithm should run in O(n) time and uses constant space.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 1;
        
        int pos = 0;
        while(pos < n) {   
            if(nums[pos] >= 1 && nums[pos] <= n && nums[pos] != pos + 1 && nums[pos] != nums[nums[pos] - 1]) {
                swap(nums[pos], nums[nums[pos] - 1]);
            } else {
                pos++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(i + 1 != nums[i]) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
