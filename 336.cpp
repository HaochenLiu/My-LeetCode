/*
336. Palindrome Pairs

Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

class Solution {
private:
    bool isP(string &s, int left, int right)
    { // check if s[left::right] is a palindrome
        while(left<right)
            if(s[left++] !=s[right--]) return false;
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> map;
        set<int> wLen;
        int it, len=words.size(), it2, sL, lL;
        vector<vector<int>> res;

        for(it=0; it<len; ++it) { //build map and the length set
            map[words[it]] = it;
            wLen.insert(words[it].size());
        }

        for(it=0; it<len; ++it)
        { // for each string
            string temp = words[it];
            lL = temp.size();
            std::reverse(temp.begin(), temp.end()); // reverse it, step a)
            if(map.count(temp) && map[temp]!=it)
                  res.push_back(vector<int>({it, map[temp]})); //step b)
            auto itC = wLen.find(words[it].size());
            for(auto itL=wLen.begin(); itL!=itC; ++itL)
            { // for each possible shorter length
                sL = *itL;
                if(isP(temp, 0, lL-sL-1) && map.count(temp.substr(lL-sL)))
                      res.push_back(vector<int>({it, map[temp.substr(lL-sL)]})); //step c1)
                if(isP(temp, sL, lL-1) && map.count(temp.substr(0,sL)))
                     res.push_back(vector<int>({map[temp.substr(0,sL)], it})); //step c2)                       
            }
        }    
        return res;
    }
};
