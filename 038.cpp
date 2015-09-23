/*
038. Count and Say
http://www.cnblogs.com/codingmylife/archive/2012/09/05/2671655.html

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string iter(string str) {
        if(str.empty()) return "";
        string res;
        int n = str.size();
        char c = str[0];
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(str[i] == c) {
                cnt++;
            } else {
                res += to_string(cnt);
                res.append(1, c);
                c = str[i];
                cnt = 1;
            }
        }
        res += to_string(cnt);
        res.append(1, c);
        
        return res;
    }

    string countAndSay(int n) {
        if(n <= 0) return "";
        if(n == 1) return "1";
        string res = "1";
        for(int i = 1; i < n; i++) {
            res = iter(res);
        }

        return res;
    }
};
