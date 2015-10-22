/*
126. Word Ladder II

Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

Note:

    All words have the same length.
    All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    void findDict2(unordered_map<string, vector<string>>& m, unordered_set<string> &wordList, unordered_set<string> &next, string str) {
        int n = str.size();
        string s = str;
        for(int i = 0; i < n; i++) {
            char t = s[i];
            for(char c = 'a'; c <= 'z'; c++) {
                if(t == c) continue;
                s[i] = c;
                if(wordList.find(s) != wordList.end()) {
                    next.insert(s);
                    m[s].push_back(str);
                }
            }
            s[i] = t;
        }
    }
    
    void output(unordered_map<string, vector<string>>& m, vector<vector<string>>& res, vector<string>& path, string& beg, string& end) {
        if(beg == end) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
        } else {
            for(int i = 0; i < m[end].size(); i++) {
                path.push_back(m[end][i]);
                output(m, res, path, beg, m[end][i]);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        vector<string> path;
        
        wordList.insert(beginWord);
        wordList.insert(endWord);
        
        unordered_set<string> cur;
        unordered_set<string> next;
        cur.insert(beginWord);
        path.push_back(endWord);
        
        while(true) {
            for(auto it = cur.begin(); it != cur.end(); it++) {
                wordList.erase(*it);
            }

            for(auto it = cur.begin(); it != cur.end(); it++) {
                findDict2(m, wordList, next, *it);
            }

            if(next.empty()) {
                return res;
            }
            
            if(next.find(endWord) != wordList.end()) {
                output(m, res, path, beginWord, endWord);
                return res;
            }

            cur = next;
            next.clear();
        }

        return res;    
    }
};
