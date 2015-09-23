/*
049. Group Anagrams

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if (strs.size() <= 1) return res;
        map<string, int> anagram;
        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (anagram.find(s) == anagram.end()) {
                anagram[s] = i;
            } else {
                if (anagram[s] >= 0) {
                    res.push_back(strs[anagram[s]]);
                    anagram[s] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};
