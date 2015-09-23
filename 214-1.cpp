/*
214. Shortest Palindrome

Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
For example:
Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Thanks to @Freezen for additional test cases.
*/

class Solution {
public:
    int longestPalindrom(string s) {
        string s1;
        s1.resize(2 * s.length() + 2);
        int idx = 0;
        s1[idx++] = '$';
        s1[idx++] = '#';
        for (char a : s) {
            s1[idx++] = a;
            s1[idx++] = '#';
        }
        vector<int> p(s1.length(), 0);
        int res = 0;
        for (int id = 0, i = 1; i < s1.length(); ++i) {
            if (i < id + p[id]) p[i] = min(p[2 * id - i], id + p[id] - i);
            else p[i] = 1;
            while (s1[i + p[i]] == s1[i - p[i]]) ++p[i];
            if (id + p[id] < i + p[i]) id = i;
            if (p[i] == i) res = max(res, i);
        }
        return res - 1;
    }
    
    string shortestPalindrome(string s) {
        int pos = longestPalindrom(s);
        string res;
        for (int i = s.length() - 1; i >= pos; --i) res.push_back(s[i]);
        return res + s;
    }
};
