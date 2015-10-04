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
DP
Time: O(mn)
Space: O(mn)
Extra space: O(mn)
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int j = 2; j <= n; j += 2) {
            if(p[j - 1] == '*') {
                dp[0][j] = true;
            } else {
                break;
            }
        }
    
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[j - 1] != '*') {
                    if(p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else {
                    if(j == 1) {
                        return false;
                    }
                    dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || (dp[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.'));
                }
            }
        }

        return dp[m][n];
    }
};
