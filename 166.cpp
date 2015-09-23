/*
166. Fraction to Recurring Decimal

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
For example,
Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
Credits:
Special thanks to @Shangrila for adding this problem and creating all test cases.
*/

//7ms
//hash中存的是余数，不是商。
// 8/2 = 4
// 1/ 8 = 0.125
// 8 / 8 = 1
// 8 / 3 = 2.(6)
// 1 / 3 = 0.(3)
// 11 / 6 = 1.8(3)
// 1 / 7  = 0.(142857)
// 50 / 7  = 7.(142857)

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long ln = numerator;
        long long ld = denominator;
        long long rem = 0;

        if (ld == 0) return "";
        if (ln == 0) return "0";
        if (ln == INT_MIN && ld == -1) return "2147483648";

        string result = "";
        unordered_map<long long, int> m;
        bool minus = (ln < 0) ^ (ld < 0);
        ln = abs(ln);
        ld = abs(ld);

        if (minus) result = "-";
        result += to_string(ln / ld);
        if (ln % ld != 0) result += ".";
        rem = ln % ld;
        while (rem != 0 && m.find(rem) == m.end()) {
            m[rem] = result.size();
            rem *= 10;
            result += to_string(rem / ld);
            rem %= ld;
        }
        if (rem != 0) {
            result.insert(m[rem], 1, '(');
            result += ")";
        }

        return result;
    }
};
