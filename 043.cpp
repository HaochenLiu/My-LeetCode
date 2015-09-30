/*
043. Multiply Strings

Given two numbers represented as strings, return multiplication of the numbers as a string.
Note: The numbers can be arbitrarily large and are non-negative.
*/

/*
Time: O(mn)
Space: O(n+m)
Extra space: O(1)
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0') return "0";
        
        string res = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        int len = 0;
        while(true) {
            bool flag = false;
            int sum = 0;
            for(int i = 0; i < num1.size(); ++i) {
                int j = len - i;
                if(j < 0 || j >= num2.size()) continue;
                sum += (num1[i] - '0') * (num2[j] - '0') ;
                flag = true;
            }
            if(!flag) break;
            sum += carry;
            carry = sum / 10;
            sum %= 10;
            res.push_back(sum + '0');
            len++;
        }
        while(carry > 0) {
            res.push_back(carry % 10 + '0');
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
