/*
371. Sum of Two Integers

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.

Show Company Tags
Show Tags
Show Similar Problems
*/

class Solution {
public:
    int getSum(int a, int b) {
        int base = a ^ b;
        int c[32];
        c[0] = 0;
        for(int i = 1; i < 32; i++) {
            c[i] = (c[i - 1] && (a & 1 || b & 1)) || (a & 1 && b & 1);
            a >>= 1;
            b >>= 1;
        }
        int carry = 0;
        for(int i = 31; i >= 0; i--) {
            carry = (carry << 1) + c[i];
        }
        return base ^ carry;
    }
};
