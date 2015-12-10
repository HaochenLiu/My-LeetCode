/*
316. Remove Duplicate Letters

Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:

Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

Credits:
Special thanks to @peisi for adding this problem and creating all test cases.
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> cnt;
        string res;
        stack<char> stk;
        vector<bool> isVisited(26, false);
        for(char each : s) {
            cnt[each]++;
        }
        
        for(int i = 0; i < s.size(); cnt[s[i]]--, i++) {
            if(isVisited[s[i] - 'a'] || (!stk.empty() && stk.top() == s[i])) {
                continue;
            }
            
            while(!stk.empty() && stk.top() > s[i] && cnt[stk.top()] > 0) {
                isVisited[stk.top() - 'a'] = false;
                stk.pop();
            }
            stk.push(s[i]);
            isVisited[s[i] - 'a'] = true;
        }

        while(!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
