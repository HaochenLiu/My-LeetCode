/*
087. Scramble String

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

   great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

   rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

   rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

/*
Time: O(n^4)
Space: O(n^3)
Extra space: O(n^3)
*/

class Solution {
private:
    int isScrambleRecur(vector<vector<vector<int>>>& dp, string& s1, string& s2, int n1, int n2, int len) {
        if(dp[n1][n2][len] != 0) return dp[n1][n2][len];
        if(s1.substr(n1, len) == s2.substr(n2, len)) {
            dp[n1][n2][len] = 1;
            return dp[n1][n2][len];
        }

        vector<int> charset(26, 0);
        for(int i = n1; i < n1 + len; i++) {
            charset[s1[i] - 'a']++;
        }

        for(int i = n2; i < n2 + len; i++) {
            charset[s2[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++) {
            if(charset[i] != 0) {
                dp[n1][n2][len] = -1;
                return dp[n1][n2][len];
            }
        }
        
        bool result;
        for(int i = 1; i < len; i++) {
            result = (isScrambleRecur(dp, s1, s2, n1, n2, i) == 1) && (isScrambleRecur(dp, s1, s2, n1 + i, n2 + i, len - i) == 1);
            if(result) {
                dp[n1][n2][len] = 1;
                return dp[n1][n2][len];
            }
            result = (isScrambleRecur(dp, s1, s2, n1 + len - i, n2, i) == 1) && (isScrambleRecur(dp, s1, s2, n1, n2 + i, len - i) == 1);
            if(result) {
                dp[n1][n2][len] = 1;
                return dp[n1][n2][len];
            }
        }

        dp[n1][n2][len] = -1;
        return dp[n1][n2][len];
    }

public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;
        int n = s1.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, 0)));
        if(isScrambleRecur(dp, s1, s2, 0, 0, n) == 1) {
            return true;
        } else {
            return false;
        }
    }
};
