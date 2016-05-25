/*
049. Group Anagrams

Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case.
*/

/*
Time: O(nL*logL)
Space: O(nL)
Extra space: O(nL)
n is number of strings in str.
L is maximum length of strs.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string,multiset<string>> mp;
        for(auto &x:strs)
        {
            auto tmp = x;
            sort(tmp.begin(),tmp.end());
            mp[tmp].insert(x);
        }
        for(auto &x:mp)
            ret.push_back(vector<string>(x.second.begin(),x.second.end()));
        return ret;
    }
};
