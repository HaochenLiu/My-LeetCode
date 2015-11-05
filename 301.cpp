/*
301. Remove Invalid Parentheses

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
Credits:
Special thanks to @hpplayer for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

class Solution {
private:
    void removeRecur(set<string>& sres, string s, int start, int cnt) {
        if(cnt < 0) return;

        while(start < s.size() && s[start] != '(' && s[start] != ')') {
            start++;
        }
        
        if(start == s.size()) {
            if(cnt != 0) return;
            if(sres.empty()) {
                sres.insert(s);
            } else {
                string t = (*sres.begin());
                if(t.size() < s.size()) {
                    sres.clear();
                }
                if(t.size() <= s.size()) {
                    sres.insert(s);
                }
            }
            return;
        }

        if(s[start] == '(') {
            removeRecur(sres, s, start + 1, cnt + 1);
            s.erase(s.begin() + start);
            removeRecur(sres, s, start, cnt);
        } else {
            removeRecur(sres, s, start + 1, cnt - 1);
            s.erase(s.begin() + start);
            removeRecur(sres, s, start, cnt);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> sres;
        removeRecur(sres, s, 0, 0);
        vector<string> res;
        for(auto it = sres.begin(); it != sres.end(); it++) {
            res.push_back(*it);
        }
        return res;
    }
};
