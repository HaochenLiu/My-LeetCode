/*
132. Palindrome Partitioning II

Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

/*
Time: O(n^2)
Space: O(n^2)
Extra space: O(n^2)
*/

class Solution{
public:
    int minCut(string s) {
        int n = s.length();
        if(n < 2) return 0;
        
        int* dp = new int[n + 1];
        for(int i = 0; i <= n; ++i) {
            dp[i] = n - i;
        }
        
        bool** m = new bool*[n];
        for(int i = 0; i < n; ++i) {
            m[i] = new bool[n];
            memset(m[i], 0, sizeof(bool) * n);
        }
        
        for(int beg = n - 1; beg >= 0; --beg) {
            for(int end = beg; end < n; ++end) {
                if(s[beg] == s[end] && (end - beg < 2 || m[beg + 1][end - 1])) {
                    m[beg][end] = true;
                    dp[beg] = min(dp[beg], dp[end + 1] + 1);
                }
            }
        }
        
        for(int i = 0; i < n; ++i) {
            delete m[i];
        }
        delete m;
        
        return dp[0] - 1;
    }
};
