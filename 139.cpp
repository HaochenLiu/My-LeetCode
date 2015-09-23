/*
139. Word Break

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length();
        bool dp[n + 1];
        memset(dp, false, sizeof(dp));
        dp[n] = true;
        for(int i = n - 1; i >= 0; i--) {
            for(unordered_set<string>::iterator it = wordDict.begin(); it != wordDict.end(); it++) {
                if(i + it->length() <= n && dp[i + it->length()] && s.substr(i, it->length()) == *it) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
