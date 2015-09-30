/*
010. Regular Expression Matching

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

/*
Time: O(mn) worst case
Space: O(1)
*/

class Solution {
public:
    bool isMatchRecur(string s, int i, string p, int j) {
        if(j == p.size()) return (i == s.size());

        if(p[j + 1] != '*') {
            return (s[i] == p[j] || (p[j] == '.' && i < s.size())) && isMatchRecur(s, i + 1, p, j + 1);
        }

        while(s[i] == p[j] || (p[j] == '.' && i < s.size())) {
            if(isMatchRecur(s, i, p, j + 2)) {
                return true;
            }
            i++;
        }
        return isMatchRecur(s, i, p, j + 2);
    }

public:
    bool isMatch(string s, string p) {
        return isMatchRecur(s, 0, p, 0);
    }
};
