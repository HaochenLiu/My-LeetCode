/*
003. Longest Substring Without Repeating Characters
O(n)

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

/*
Time: O(n)
Space: O(1)
Stack depth: O(1)
256 is O(1)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool exist[256];
        memset(exist, false, sizeof(exist));
        int res = 0;
        int start = 0, end = 0, N = s.size();
        while (end < N && start + res < N)
        {
            if (!exist[s[end]]) {
                exist[s[end++]] = true;
            } else {
                exist[s[start++]] = false;
            }
            res = max(end - start, res);
        }
        return res;
    }
};
