/*
201. Bitwise AND of Numbers Range

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
For example, given the range [5, 7], you should return 4.
Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0) return 0;
        if(m == n) return m;
        if(m <= n / 2) return 0;
        unsigned int res = m;
        for(unsigned int i = m + 1; i <= n; i++) {
            res &= i;
        }
        return res;
    }
};
