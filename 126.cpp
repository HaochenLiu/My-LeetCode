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
    unordered_map<string, vector<string>> m;
    vector<vector<string>> res;
    vector<string> path;
    
    void findDict2(string str, unordered_set<string> &dict, unordered_set<string> &next_lev) {
        int n = str.size();
        string s = str;
        for(int i = 0; i < n; i++) {
            char t = s[i];
            for(char c = 'a'; c <= 'z'; c++) {
                if(t == c) continue;
                s[i] = c;
                if(dict.find(s) != dict.end()) {
                    next_lev.insert(s);
                    m[s].push_back(str);
                }
            }
            s[i] = t;
        }
    }
    
    void output(string &start, string last){
        if(last == start){
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
        } else {
            for(int i = 0; i < m[last].size(); i++){
                path.push_back(m[last][i]);
                output(start,m[last][i]);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        m.clear();
        res.clear();
        path.clear();
        
        wordList.insert(beginWord);
        wordList.insert(endWord);
        
        unordered_set<string> cur_lev;
        cur_lev.insert(beginWord);
        unordered_set<string> next_lev;
        path.push_back(endWord);
        
        while(true) {
            for(auto it = cur_lev.begin(); it != cur_lev.end(); it++) {
                wordList.erase(*it);
            }

            for(auto it = cur_lev.begin(); it != cur_lev.end(); it++) {
                findDict2(*it, wordList, next_lev);
            }

            if(next_lev.empty()) {
                return res;
            }
            
            if(next_lev.find(endWord) != wordList.end()) {
                output(beginWord, endWord);
                return res;
            }

            cur_lev = next_lev;
            next_lev.clear();
        }
        return res;    
    }
};
