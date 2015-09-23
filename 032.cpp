/*
032. Longest Valid Parentheses
O(n)

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int res = 0;
        int cur = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == ')') {
                if(st.empty()) {
                    cur = 0;
                    continue;
                } else {
                    cur += (2 + st.top());
                    st.pop();
                    res = max(res, cur);
                }
            } else {
                st.push(cur);
                cur = 0;
            }
        }
        return res;
    }
};
