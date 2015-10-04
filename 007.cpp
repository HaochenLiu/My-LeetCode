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
Extra space: O(1)
*/

class Solution {
public:
    int reverse(int x) {
        long long lx = x;
        long long res = 0;
        while(lx) {
            res *= 10;
            res += (lx % 10);
            lx /= 10;
            if(res > INT_MAX || res < INT_MIN) {
                return 0;
            }
        }
        return res;
    }
};
