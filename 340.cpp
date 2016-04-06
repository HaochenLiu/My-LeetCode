/*
340. Longest Substring with At Most K Distinct Characters

Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.length() == 0) return 0;
        int pstart = 0, pend = 0;
        int hashTable[256] = {0};
        int appearedChars = 0;
        int maxLen = 0;
        for (; pend < s.length(); pend++) {
            char curChar = s[pend];
            if (hashTable[curChar] == 0) appearedChars += 1;
            hashTable[curChar]++;

            while (appearedChars > k && pstart < s.length()) {
                hashTable[s[pstart]]--;
                if (hashTable[s[pstart]] == 0) appearedChars -= 1;
                pstart++;
            }

            if (pend - pstart + 1 > maxLen)
                maxLen = pend - pstart + 1;
        }
        return maxLen;
    }
};
