/*
231. Power of Two

Given an integer, write a function to determine if it is a power of two.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long num = 1;
        while(num <= n) {
            if(num == n) {
                return true;
            }
            num = num << 1;
        }
        return false;
    }
};
