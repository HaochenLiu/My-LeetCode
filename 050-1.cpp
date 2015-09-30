/*
050. Pow(x, n)

Implement pow(x, n).
*/

/*
Time: O(logn)
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0.0) return 0.0;
        if(x == 1.0) return 1.0;
        if(x < 0 && n % 2 == 1) return -myPow(-x, n);
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n < 0) {
            if(n != INT_MIN) {
                return 1 / myPow(x, -n);
            } else {
                return 1 / myPow(x, INT_MAX) / x;
            }
        }
        double t = myPow(x, n / 2);
        if(n % 2 == 0) {
            return t * t;
        } else {
            return t * t * x;
        }
    }
};
