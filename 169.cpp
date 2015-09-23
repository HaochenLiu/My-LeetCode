/*
169. Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int vote = 1;
        int cur = nums[0];
        for(int i = 1; i < n; i++) {
            if(vote == 0) {
                vote = 1;
                cur = nums[i];
            } else if(cur == nums[i]) {
                vote++;
            } else {
                vote--;
            }
        }

        return cur;
    }
};
