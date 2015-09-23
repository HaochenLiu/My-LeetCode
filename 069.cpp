/*
069. Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        long long val = x;
        long long beg = 1;
        long long end = 50000;
        while(beg < end) {
            long long mid = beg + (end - beg) / 2;
            if(mid * mid == val) {
                return (int)mid;
            } else if(mid * mid > val) {
                end = mid - 1;
            } else {
                if((mid + 1) * (mid + 1) > val) {
                    return (int)mid;
                }
                beg = mid + 1;
            }
        }
        
        return (int)beg;
    }
};
