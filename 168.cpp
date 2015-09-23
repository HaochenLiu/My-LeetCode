
168. Excel Sheet Column Title

Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases.

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n != 0) {
            if(n % 26 != 0) {
                res = char((n % 26) + 'A' - 1) + res;
                n /= 26;
            } else {
                res = 'Z' + res;
                n /= 26;
                n--;
            }
        }
        return res;
    }
};
