/*
140. Word Break II

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

class Solution {
public:
    bool dp[1000];
    vector<string> record[1000];
    string str;
    vector<string> result;

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        result.clear();
        if(s.size() == 0 ) return result;

        for(int i = 0; i < 1000; ++i) {
            record[i].clear();
        }
        memset(dp, false, sizeof(dp));
 
        dp[s.size()] = true;
        for(int i = s.size() - 1; i >= 0; i --) {
            int len1 = s.size() - i;
            for(unordered_set<string>::iterator it_set = dict.begin(); it_set != dict.end(); it_set++) {
                int len2 = it_set->size();
                if(len1 >= len2) {
                    if(dp[i + len2] && s.substr(i, len2) == *it_set) {
                        dp[i] = true;
                        record[i].push_back(*it_set);
                    }
                }
            }
        }
 
        if(!dp[0]) {
            return result;
        } else {
            str = s;
            dfs(0, "");
            return result;
        }
    }
     
    void dfs(const int &i, string oneSolution) {
        if(i == str.size()) {
            result.push_back(oneSolution);
        }
 
        for(int s = 0; s < record[i].size(); ++s) {
            string newStr = record[i][s];
            if(i + newStr.size() != str.size()) {
                newStr.push_back(' ');
            }
            string copySolution = oneSolution;
            copySolution.append(newStr);
            dfs(i + record[i][s].size(), copySolution);
        }
    }
};
