/*
311. Sparse Matrix Multiplication

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        if(A.empty() || A[0].empty() || B.empty() || B[0].empty()) return res;
        int a = A.size();
        int b = A[0].size();
        int c = B[0].size();
        res.resize(a, vector<int>(c, 0));
    
        vector<pair<int, int>> m1;
        unordered_map<int, vector<int>> m2;
    
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                if(A[i][j] != 0) {
                    m1.push_back(make_pair(i, j));
                }
            }
        }

        for(int i = 0; i < b; i++) {
            for(int j = 0; j < c; j++) {
                if(B[i][j] != 0) {
                    m2[i].push_back(j);
                }
            }
        }

        for(int i = 0; i < m1.size(); i++) {
            pair<int, int> p = m1[i];
            int x1 = p.first;
            int y1 = p.second;
            int val1 = A[x1][y1];
            int x2 = y1;
            vector<int> v2 = m2[x2];
            int n2 = v2.size();
            for(int j = 0; j < n2; j++) {
                int y2 = v2[j];
                int val2 = B[x2][y2];
                res[x1][y2] += val1 * val2;
            }
        }
        
        return res;
    }
};
