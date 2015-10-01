/*
077. Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

/*
Time: O(C(n,k))
Space: O(k)
Extra space: O(k)
*/

class Solution {
private:
    void solve(vector<vector<int>>& res, vector<int>& record, int dep, int maxDep, int n, int start) {
        if (dep == maxDep) {
            res.push_back(record);
            return;
        }
        
        for(int i = start; i <= n; i++) {
            record[dep] = i;
            solve(res, record, dep + 1, maxDep, n, i + 1);
        }      
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> record;
        record.resize(k);
        solve(res, record, 0, k, n, 1);
        return res;
    }
};
