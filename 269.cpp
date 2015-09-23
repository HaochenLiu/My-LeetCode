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

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 1) return words[0];
        graph g = make_graph(words);
        return toposort(g);
    }

private:
    typedef unordered_map<char, unordered_set<char>> graph;
    
    graph make_graph(vector<string>& words) {
        graph g;
        int n = words.size();
        for (int i = 1; i < n; i++) {
            bool found = false;
            string word1 = words[i - 1];
            string word2 = words[i];
            int m = word1.length();
            int n = word2.length();
            int l = max(m, n);
            for (int j = 0; j < l; j++) {
                if (j < m && g.find(word1[j]) == g.end()) {
                    g[word1[j]] = unordered_set<char>();
                }
                if (j < n && g.find(word2[j]) == g.end()) {
                    g[word2[j]] = unordered_set<char>();
                }
                if (j < m && j < n && word1[j] != word2[j] && !found) {
                    g[word1[j]].insert(word2[j]);
                    found = true;
                }
            }
        }
        return g;
    }
    
    string toposort(graph& g) {
        vector<bool> path(256, false);
        vector<bool> visited(256, false);
        string topo;
        for (auto adj : g) {
            if (!acyclic(g, path, visited, topo, adj.first)) {
                return "";
            }
        }
        reverse(topo.begin(), topo.end());
        return topo;
    }
    
    bool acyclic(graph& g, vector<bool>& path, vector<bool>& visited, string& topo, char node) {
        if (path[node]) return false;
        if (visited[node]) return true;
        path[node] = true;
        visited[node] = true;
        for (auto neigh : g[node]) {
            if (!acyclic(g, path, visited, topo, neigh)) {
                return false;
            }
        }
        path[node] = false;
        topo += node;
        return true;
    }
};
