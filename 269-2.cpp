/*
269. Alien Dictionary

There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
For example,
Given the following words in dictionary,
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]


The correct order is: "wertf".
Note:
You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/

/*
Time: O(E+V) = O(E)
Space: O(E)
Extra space: O(E)
E is the number of edges in graph.
V = O(1) is the number of vertices in graph.
*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        string res = "";
        if(n == 0) return res;
        vector<vector<int>> dictPair;
        vector<int> inDegree(26, 0);
        vector<bool> exist(26, false);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < words[i].size(); j++) {
                exist[words[i][j] - 'a'] = true;
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < min(words[i - 1].size(), words[i].size()); j++) {
                if(words[i - 1][j] == words[i][j]) {
                    continue;
                } else {
                    inDegree[words[i][j] - 'a']++;
                    dictPair.push_back(vector<int>{words[i - 1][j] - 'a', words[i][j] - 'a'});
                    break;
                }
            }
        }
        
        queue<int> q;
        for(int i = 0; i < inDegree.size(); i++) {
            if(inDegree[i] == 0 && exist[i]) {
                q.push(i);
                res.append(1, 'a' + i);
            }
        }
        
        while(!q.empty()) {
            int a = q.front();
            q.pop();
            for(int i = 0; i < dictPair.size(); i++) {
                if(dictPair[i][0] == a) {
                    inDegree[dictPair[i][1]]--;
                    if(inDegree[dictPair[i][1]] == 0) {
                        q.push(dictPair[i][1]);
                        res.append(1, dictPair[i][1] + 'a');
                    }
                }
            }
        }

        for(int i = 0; i < inDegree.size(); i++) {
            if(inDegree[i] != 0) {
                return "";
            }
        }
        
        return res;
    }
};
