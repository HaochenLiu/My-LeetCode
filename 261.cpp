/*
261. Graph Valid Tree

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
For example:
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
Hint:
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(n == 0) return true;
        int e = edges.size();
        if(e != n - 1) return false;
        vector<int> degree(n, 0);
        for(int i = 0; i < e; i++) {
            degree[edges[i].first]++;
            degree[edges[i].second]++;
        }
        
        queue<int> q;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(degree[i] < 2) {
                q.push(i);
                res.push_back(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int i = 0; i < e; i++) {
                if(edges[i].first == node || edges[i].second == node) {
                    degree[edges[i].first]--;
                    degree[edges[i].second]--;
                    if(degree[edges[i].first] == 1) {
                        q.push(edges[i].first);
                        res.push_back(edges[i].first);
                    }
                    if(degree[edges[i].second] == 1) {
                        q.push(edges[i].second);
                        res.push_back(edges[i].second);
                    }
                }
            }
        }
        
        return (res.size() == n);
    }
};
