/*
367. Valid Perfect Square

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(!num)
            return false;
        if(num == 1)
            return true;
        return findTarget(num);
    }
private:
    bool findTarget(int num){
        int l = 2, r = num - 1;
        while(l <= r){
            long long mid = (l + r)>>1;
            long long val = mid*mid;
            if(val == num)
                return true;
            else if(val < num)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};
