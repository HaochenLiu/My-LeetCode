/*
014. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings. 
*/

/*
Time: O(nL)
Space: O(L)
L is the maximum length of string.
n is number of strings.
*/

class Solution {
public:
    string findCommon(string s1, string s2) {
        int n = min(s1.length(), s2.length());
        for(int i = 0; i < n; ++i) {
            if(s1[i] != s2[i]) return s1.substr(0, i);
        }
        return s1.substr(0, n);
    }

    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];

        string res = strs[0];
        for(int i = 1; i < strs.size(); ++i) {
            res = findCommon(res, strs[i]);
        }
        return res;
    }
};
