/*
058. Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(s[0] == '\0') return 0;
        
        int res = 0;
        int n = strlen(s);
        int pos = n - 1;
        while(s[pos] == ' ') {
            pos--;
        }
        
        if(pos == -1) return 0;
        
        for(int i = pos; i >= 0; i--) {
            if(s[i] == ' ') {
                return (pos - i);
            }
        }
        return pos + 1;
    }
};
