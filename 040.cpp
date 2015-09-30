/*
040. Combination Sum II

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.
Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

/*
Time: O(2^n)
Space: O(2^n)
Extra space: O(n)
n is the length of candidates.
*/

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& record, vector<int>& candidates, int index, int target) {
        if(target == 0) {
            res.push_back(record);
            return;
        }
        if(index == candidates.size()) {
            return;
        }
        if(candidates[index] > target) {
            return;
        }
        dfs(res, record, candidates, index + 1, target);
        record.push_back(candidates[index]);
        dfs(res, record, candidates, index + 1, target - candidates[index]);
        record.pop_back();
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> record;
        sort(candidates.begin(), candidates.end());
        dfs(res, record, candidates, 0, target);
        sort(res.begin(), res.end());
        auto pos = unique(res.begin(), res.end());
        res.erase(pos, res.end());
        return res;
    }
};
