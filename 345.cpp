/*
345. Reverse Vowels of a String

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
*/

class Solution {
public:
    bool isVowel (char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

    string reverseVowels (string s) {
        if (s.size() <= 1) return s;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (isVowel(s[i]) && isVowel(s[j]))
                swap(s[i++], s[j--]);
            else {
                if (!isVowel(s[i])) ++i;
                if (!isVowel(s[j])) --j;
            }
        }
        return s;
    }
};
