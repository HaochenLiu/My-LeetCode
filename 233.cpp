/*
233. Number of Digit One

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
Hint:
Beware of overflow.
*/

class Solution {
public:
    int countDigitOne(int n) {
        long long int res = 0;
        int highn = n;
        int lowc = 1;
        int lown = 0;
        while(highn > 0){
            int curn = highn % 10;
            highn = highn / 10;
            if (1 == curn) {
                //higher: 0~(highn-1);  lower:  0 ~ (lowc-1)
                res += (highn * lowc);
                //higher: highn ~ highn;     lower:0~lown
                res += (lown + 1);
            } else if (0 == curn) {  
                //curn < 1
                //higher: 0~(highn-1);  lower:  0 ~ (lowc-1)
                res += (highn * lowc);
            } else {              
                //curn > 1
                res += (highn + 1) * lowc;
            }
            //update lown and lowc
            lown = curn * lowc + lown;
            lowc = lowc * 10;
        }
        return res;
    }
};
