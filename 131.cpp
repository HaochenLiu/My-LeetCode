/*
131. Palindrome Partitioning
http://www.cnblogs.com/lihaozy/p/3182262.html

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

class Solution {
public:
    bool isPail(string &s) {
        int low = 0, high = s.length() - 1;
        while (low < high) {
            if (s[low] != s[high]) {
                return false;
            }
            ++low;
            --high;
        }
        return true;
    }
    
    void findNext(vector<vector<string> > &res, string &s, vector<string> part, int idx) {
        if (idx == s.length()) {
            res.push_back(part);
            return;
        }
        string substr;
        for (int len = s.length() - idx; len > 0; --len) {
            substr = s.substr(idx, len);
            if (isPail(substr)) {
                part.push_back(substr);
                findNext(res, s, part, idx + len);
                part.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> part;
        findNext(res, s, part, 0);
        return res;
    }
};
