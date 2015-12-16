/*
058. Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/

/*
Time: O(n)
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ind1 = s.find_last_not_of(' ');
        s = s.substr(0, ind1 + 1);
        int ind2 = s.find_last_of(' ');
        if(ind2 >= s.size()) {
            return s.size();
        } else {
            return s.size() - ind2 - 1;
        }
    }
};
