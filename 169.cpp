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
        vector<int> countsPerBit(32, 0);
        int result = 0;

        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if(((nums[j]>>i) & 1) == 1) {
                    count++;
                }
            }

            if (count > nums.size() / 2) {
                result |= (1<<i);
            }
        }

        return result;
    }
};
