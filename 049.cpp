/*
049. Group Anagrams

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
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
