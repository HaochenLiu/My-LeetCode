/*
306. Additive Number

Additive number is a positive integer whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string represents an integer, write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?

Credits:
Special thanks to @jeantimex for adding this problem and creating all test cases.
*/

class Solution {
private:
    string strAdd(string& s1, string& s2) {
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int k = max(s1.size(), s2.size());
        int tmp = 0;
        string res(k + 1, '0');
        while(i >= 0 || j >= 0 || tmp) {
            if(i >= 0) {
                tmp += s1[i] - '0';
            }

            if(j >= 0) {
                tmp += s2[j] - '0';
            }
            
            res[k] = (tmp % 10 + '0');
            tmp /= 10;

            i--;
            j--;
            k--;
        }
        
        while(res.size() > 1 && res[0] == '0') {
            res.erase(res.begin());
        }

        return res;
    }

public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        if(n < 3) return false;
        for(int i = 1; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(num[i] == '0' && j > i) continue;
                string s1 = num.substr(0, i);
                string s2 = num.substr(i, j - i + 1);
                int curLen = j + 1;
                string s3 = strAdd(s1, s2);
                int nextLen = s3.size();
                if(nextLen > n - curLen) {
                    continue;
                }
                if(num.substr(curLen, nextLen) != s3) {
                    continue;
                }
                if(nextLen == n - curLen) {
                    return true;
                }
                while(true) {
                    s1 = s2;
                    s2 = s3;
                    curLen += nextLen;
                    s3 = strAdd(s1, s2);
                    nextLen = s3.size();
                    if(nextLen > n - curLen) {
                        break;
                    }
                    if(num.substr(curLen, nextLen) != s3) {
                        break;
                    }
                    if(nextLen == n - curLen) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
