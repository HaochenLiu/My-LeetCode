/*
125. Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

/*
Time: O(n^2)
Space: O(n)
Extra space: O(1)
*/

class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(isalpha(s[i])) {
                s[i] = tolower(s[i]);
            } else if(!isdigit(s[i])) {
                s.erase(s.begin() + i);
                i--;
            }
        }
        
        for(int i = 0; i < s.size() / 2; i++) {
            if(s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
