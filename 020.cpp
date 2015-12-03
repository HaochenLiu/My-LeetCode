/*
020. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

/*
stack
Time: O(n)
Space: O(n)
Extra space: O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != ')' && s[i] != ']' && s[i] != '}') {
                st.push(s[i]);
            } else if(s[i] == ')') {
                if(st.empty() || st.top() != '(') return false;
                st.pop();
            } else if(s[i] == ']') {
                if(st.empty() || st.top() != '[') return false;
                st.pop();
            } else {
                if(st.empty() || st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
