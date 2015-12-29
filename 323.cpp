/*
323. Number of Connected Components in an Undirected Graph

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

     0          3
     |          |
     1 --- 2    4

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:

     0           4
     |           |
     1 --- 2 --- 3

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges. 
*/

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) 
    {
        int ret = n;
        vector<pair<int, int>> sets(n);
        for (int i = 0; i < n; i++)
        {
            sets[i].first = i;
            sets[i].second = 0;
        }
    
        function<int(int)> find = [&](int i)
        {
            if (sets[i].first != i)
                sets[i].first = find(sets[i].first);
    
            return sets[i].first;
        };
    
        for (auto &edge : edges)
        {
            int x = find(edge.first), y = find(edge.second);
            if (x != y)
            {
                if (sets[x].second > sets[y].second)
                {
                    sets[y].first = x;
                }
                else
                {
                    sets[x].first = y;
                    if (sets[x].second == sets[y].second)
                    {
                        sets[y].second++;
                    }
                }
                n--;
            }
        }
        return n;
    }
};
