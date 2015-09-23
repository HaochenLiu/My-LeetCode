/*
172. Factorial Trailing Zeroes

Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n != 0) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};
