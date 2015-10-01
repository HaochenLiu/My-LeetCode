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

/*
Time: O(n^3)
Space: O(n)
Extra space: O(1)
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
    
    void findNext(vector<vector<string> > &res, string &s, vector<string> record, int idx) {
        if (idx == s.length()) {
            res.push_back(record);
            return;
        }
        string substr;
        for (int len = s.length() - idx; len > 0; --len) {
            substr = s.substr(idx, len);
            if (isPail(substr)) {
                record.push_back(substr);
                findNext(res, s, record, idx + len);
                record.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> record;
        findNext(res, s, record, 0);
        return res;
    }
};
