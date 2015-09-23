/*
260. Single Number III

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
For example:
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {  
public:  
    vector<int> singleNumber(vector<int>& nums) {  
        int len = nums.size();  
        int AxorB = 0;  
        for(int i = 0; i < len; i++){  
            AxorB ^= nums[i];  
        }  
        int mask = AxorB & (~(AxorB - 1));  
        int A = 0;  
        int B = 0;  
        for(int i = 0; i < len; i++){  
            if((mask & nums[i]) == 0){  
                A ^= nums[i];  
            }else{  
                B ^= nums[i];  
            }  
        }  
        return vector<int>{A, B};  
    }  
};
