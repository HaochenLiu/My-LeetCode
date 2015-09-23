/*
044. Wildcard Matching

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

贪心法
O(mn)
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int jstar = -1;
        int istar = -1;
        int i = 0;
        int j = 0;
        while(i < s.size()) {
            if(s[i] == p[j] || p[j] == '?') {
                i++;
                j++;
                continue;
            }
            if(p[j] == '*') {
                jstar = j;
                j++;
                istar = i;
                continue;
            }
            if(jstar != -1) {
                j = jstar + 1;
                istar++;
                i = istar;
                continue;
            }
            return false;
        }
        while(p[j] == '*') {
            j++;
        }
        return (j == p.size());
    }
};
