/*
066. Plus One
http://blog.csdn.net/xiadasong007/article/details/4031184

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        digits[n - 1]++;
        for(int i = n - 1; i >= 0; --i) {
            if(digits[i] > 9) {
                if(i != 0) {
                    digits[i] -= 10;
                    digits[i - 1]++;
                } else {
                    digits[0] -= 10;
                    digits.insert(digits.begin(), 1, 1); 
                    return digits;
                }
            } else {
                return digits;
            }
        }
        return digits;
    }
};
