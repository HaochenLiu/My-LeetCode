/*
279. Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

/*
Time: O(sqrt(n))
Space: O(1)
Extra space: O(1)
*/

class Solution {
private:
    bool isSquare(int n) {
        int t = sqrt(n);
        return (t * t == n);
    }
    
public:
    int numSquares(int n) {
        while(!(n & 3)) {
            n >>= 2;
        }

        if(isSquare(n)) {
            return 1;
        }
        
        if((n & 7) == 7) {
            return 4;
        }

        for(int i = 1; i <= n / i; i++) {
            if(isSquare(n - i * i)) {
                return 2;
            }
        }
        return 3;
    }
};
