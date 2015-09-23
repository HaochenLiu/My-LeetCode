/*
029. Divide Two Integers
防溢出

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        long long a = dividend;
        long long b = divisor;
        a = abs(a);
        b = abs(b);
        
        long long res = 0;
        while(a >= b) {
            long long t = b;
            long long quo = 1;
            while(a >= t) {
                a -= t;
                res += quo;
                quo <<= 1;
                t <<= 1;
            }
        }
        return ((dividend < 0) ^ (divisor < 0)) ? -res: res;
    }
};

/*
不能写
long long a = abs(dividend);
*/
