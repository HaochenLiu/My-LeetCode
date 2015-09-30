/*
005. Longest Palindromic Substring

http://blog.csdn.net/linulysses/article/details/5634104
Manacher's ALGORITHM: O(n)时间求字符串的最长回文子串
http://www.felix021.com/blog/read.php?2040
http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

/*
DP
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2) return s;
        string str = "#";
        for(int i = 0; i < s.size(); ++i) {
            str.push_back(s[i]);
            str.push_back('#');
        }
        vector<int> dp(str.size(), 0);
        int R = 0;
        int C = 0;
        int len = 0;
        for(int i = 0; i < dp.size(); ++i) {
            if(i < R) {
                dp[i] = min(dp[2 * C - i], R- i);
            } else {
                dp[i] = 1;
            }
            while(i >= dp[i] && i + dp[i] < dp.size() && str[i + dp[i]] == str[i - dp[i]]) {
                dp[i]++;
            }
            dp[i]--;
            
            if(dp[i] > len) {
                len = dp[i];
                C = i;
                R = i + dp[i];
            }
        }
        return s.substr((C - dp[C]) / 2, dp[C]);
    }
};
