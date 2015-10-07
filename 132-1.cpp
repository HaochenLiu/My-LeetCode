/*
132. Palindrome Partitioning II

Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

/*
Time: O(n^2)
Space: O(n)
Extra space: O(n)
*/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n < 2) return 0;
        vector<int> cut(n + 1, INT_MAX);
        cut[0] = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i && i + j < n && s[i + j] == s[i - j]; j++) {
                cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j]);
            }
            for(int j = 1; j <= i + 1 && i + j < n && s[i + j] == s[i - j + 1]; j++) {
                cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j + 1]);
            }
        }
        return cut[n];
    }
};
