/*
009. Palindrome Number
O(n)
负数不是回文数

Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.
Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }
    
    bool isPalindrome(int x) {
        return (x >= 0) && (x == reverse(x));
    }
};
