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
    double power(double x, int n) {
        if(n == 0) return 1.0;
        double t = power(x, n / 2);
        if(n % 2 == 0) {
            return t * t;
        } else {
            return t * t * x;
        }
    }
    
    double myPow(double x, int n) {
        if(n >= 0) {
            return power(x, n);
        } else {
            double t = 1.0 / power(x, n / 2);
            if(n % 2 == 0) {
                return t * t;
            } else {
                return t * t / x;
            }
        }
    }
};
