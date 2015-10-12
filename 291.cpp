/*
291. Word Pattern II

Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:

    pattern = "abab", str = "redblueredblue" should return true.
    pattern = "aaaa", str = "asdasdasdasd" should return true.
    pattern = "aabb", str = "xyzabcxzyabc" should return false.

Notes:
You may assume both pattern and str contains only lowercase letters. 
*/

class Solution {
private:
    bool dfs(vector<string>& match, vector<int>& idx, unordered_set<string>& s, int start, string& pattern, string& str) {
        int n = pattern.size();
        int m = str.size();
        if(start == n) {
            return (idx[n - 1] == m);
        }

        int prevIdx = 0;
        if(start > 0) {
            prevIdx = idx[start - 1];
        }

        if(n - start > m - prevIdx) {
            return false;
        }

        if(match[pattern[start] - 'a'] != "") {
            int sz = match[pattern[start] - 'a'].size();
            if(m - prevIdx < sz) {
                return false;
            }
            if(match[pattern[start] - 'a'] != str.substr(prevIdx, sz)) {
                return false;
            }
            idx[start] = prevIdx + sz;
            return dfs(match, idx, s, start + 1, pattern, str);
        }

        for(int len = 1; prevIdx + len <= m; len++) {
            if(s.find(str.substr(prevIdx, len)) != s.end()) {
                continue;
            }
            match[pattern[start] - 'a'] = str.substr(prevIdx, len);
            s.insert(match[pattern[start] - 'a']);
            idx[start] = prevIdx + len;
            if(dfs(match, idx, s, start + 1, pattern, str)) {
                return true;
            }
            s.erase(match[pattern[start] - 'a']);
            match[pattern[start] - 'a'] = "";
        }

        return false;
    }
    
public:
    bool wordPatternMatch(string pattern, string str) {
        if(pattern == str) return true;
        if(pattern.empty() || str.empty()) return false;
        int n = pattern.size();
        int m = str.size();
        if(n > m) return false;
        vector<string> match(26, "");
        vector<int> idx(n, 0);
        unordered_set<string> s;
        return dfs(match, idx, s, 0, pattern, str);
    }
};
