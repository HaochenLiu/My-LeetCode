/*
290. Word Pattern

Given a pattern and a string str, find if str follows the same pattern.

Examples:

    pattern = "abba", str = "dog cat cat dog" should return true.
    pattern = "abba", str = "dog cat cat fish" should return false.
    pattern = "aaaa", str = "dog cat cat dog" should return false.
    pattern = "abba", str = "dog dog dog dog" should return false.

Notes:

    Both pattern and str contains only lowercase alphabetical letters.
    Both pattern and str do not have leading or trailing spaces.
    Each word in str is separated by a single space.
    Each letter in pattern must map to a word with length that is at least 1.

Credits:
Special thanks to @minglotus6 for adding this problem and creating all test cases.
*/

class Solution {
private:
    vector<string> split(string str) {
        vector<string> res;
        int n = str.size();
        if(n == 0) {
            return res;
        }
        int beg = 0;
        int end = 0;
        while(end < n) {
            while(end < n && str[end] != ' ') {
                end++;
            }
            res.push_back(str.substr(beg, end - beg));
            beg = end + 1;
            end = beg;
        }
        return res;
    }

public:
    bool wordPattern(string pattern, string str) {
        int n = pattern.size();
        vector<string> s = split(str);
        if(n != s.size()) return false;
        map<char, string> m1;
        map<string, char> m2;
        for(int i = 0; i < n; i++) {
            if(m1.find(pattern[i]) == m1.end()) {
                m1[pattern[i]] = s[i];
            } else if(m1[pattern[i]] != s[i]) {
                return false;
            }
            
            if(m2.find(s[i]) == m2.end()) {
                m2[s[i]] = pattern[i];
            } else if(m2[s[i]] != pattern[i]) {
                return false;
            }
        }
        
        return true;
    }
};
