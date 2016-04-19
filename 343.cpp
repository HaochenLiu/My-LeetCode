/*
343. Integer Break

Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.

Hint:

There is a simple O(n) solution to this problem.
You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    int integerBreak(int n) {
        int prod=1;
        if(n==1 || n==2)
            return prod;
        if(n==3)
            return 2;
        while(n>=3){
            if(n==4){
                prod = prod *4;
                n-=4;
                break;
            }
            prod = prod*3;
            n-=3;
        }
        if(n==2){
            prod = prod * 2;
        }
        return prod;
    }
};
