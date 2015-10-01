/*
089. Gray Code

The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

/*
Time: O(2^n)
Space: O(2^n)
Extra space: O(1)
*/

class Solution {
public:
    int Power2(int n) {
        return 1 << n;
    } 

    vector<int> grayCode(int n) {
        vector<int> res;
        if(n == 0) {
            res.push_back(0);
            return res;
        }
        
        if(n == 1) {
            res.push_back(0);
            res.push_back(1);
            return res;
        }

        res.push_back(0);
        res.push_back(1);

        for(int i = 2; i <= n; ++i) {
            for(int j = Power2(i - 1) - 1; j >= 0; --j) {
                res.push_back(Power2(i - 1) + res[j]);
            }
        }
        
        return res;
    }
};
