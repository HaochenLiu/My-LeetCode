/*
159. Longest Substring with At Most Two Distinct Characters

Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
For example, Given s = “eceba”,
T is "ece" which its length is 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int maxEndHere = 1;
        int maxSoFar = 1;
        int lastCharLen = 1;
        char preChar = '\0';
        char lastChar = s[0];
        for (int i = 1; i < n; i++) {
            if(s[i] == lastChar) {
                maxEndHere++;
                lastCharLen++;
            } else if(s[i] == preChar) {
                maxEndHere++;
                preChar = lastChar;
                lastChar = s[i];
                lastCharLen = 1;
            } else {
                maxEndHere = lastCharLen + 1;
                preChar = lastChar;
                lastChar = s[i];
                lastCharLen = 1;
            }
            maxSoFar = max(maxSoFar, maxEndHere);
        }
        return maxSoFar;
    }
};
