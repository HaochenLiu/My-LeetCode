/*
007. Reverse Integer

Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321
click to show spoilers.
Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
Update (2014-11-10):
Test cases had been added to test the overflow behavior.
*/

/*
Time: O(1)
Space: O(1)
*/

class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        
        int res = 0;
        int tmp = abs(x);
        while(tmp != 0) {
            if(res > INT_MAX / 10 || (res == INT_MAX / 10) && tmp % 10 > 7) {
                return 0;
            }
            res *= 10;
            res += (tmp % 10);
            tmp /= 10;
        }
        
        if(x < 0) {
            res = -res;
        }
        return res;
    }
};
