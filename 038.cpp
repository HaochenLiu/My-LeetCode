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
    string convert(string say) {
        stringstream ss;
        int count = 0;
        char last = say[0];
        for(int i = 0; i <= say.length(); ++i) {
            if(say[i] == last) {
                count++;
            } else {
                ss << count << last;
                count = 1;
                last = say[i];
            }
        }
        return ss.str();
    }
    
    string countAndSay(int n) {
        if(n <= 0) return string();
        string say = "1";
        for(int i = 1; i < n; ++i) {
            say = convert(say);
        }
        return say;
    }
};
