/*
115. Distinct Subsequences

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        if(lent == 0) {
            return 1;
        } else if(lens == 0) {
            return 0;
        } else if(lens < lent) {
            return 0;
        }
        
        int dp[lens + 1][lent + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= lens; i++) {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= lens; i++) {
            for(int j = 1; j <= lent; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[lens][lent];
    }
};
