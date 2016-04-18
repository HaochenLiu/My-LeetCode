/*
342. Power of Four

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

Credits:
Special thanks to @yukuairoy for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        // Mark every possible '1' position in the integer.
        int max1 = 1431655765; //0b1010101010101010101010101010101

        int max2 = (1 << 30);
        // 1) check if num is a power of 2
        // 2) check if num's '1' position changes any '0' in max1 to '1'.
        if (num > 0 && (max2 % num == 0) && ((max1 | num) == max1)) return true;
        return false;
    }
};
