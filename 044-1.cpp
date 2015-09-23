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

DP
O(mn)
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int j = 1; j <= n; j++) {
            dp[0][j] = (p[j - 1] == '*') && dp[0][j - 1];
        }
       
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[j - 1] != '*') {
                    if(p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};
