/*
205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.
Note:
You may assume both s and t have the same length.
*/

class Solution {
private:
    bool isIsomorphicHelper(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        if(n == 0) return true;
        bool flag[n];
        memset(flag, false, sizeof(flag));
        for(int i = 0; i < n; i++) {
            if(flag[i]) continue;
            flag[i] = true;
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j]) {
                    if(t[i] == t[j]) {
                        flag[j] = true;
                    } else
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    bool isIsomorphic(string s, string t) {
        return isIsomorphicHelper(s, t) && isIsomorphicHelper(t, s);
    }
};
