/*
039. Combination Sum

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/

class Solution {
private:
    void dfs(vector<vector<int> > &res, vector<int> &candidates, vector<int> &record, int index, int target) {
        if(target == 0) {
            res.push_back(record);
            return;
        }
        if(index == candidates.size()) return;
        if(candidates[index] > target) return;
        
        dfs(res, candidates, record, index + 1, target);
        for(int i = 1; i <= target / candidates[index]; ++i) {
            record.push_back(candidates[index]);
            dfs(res, candidates, record, index + 1, target - i * candidates[index]);
        }

        for(int i = 1; i <= target / candidates[index]; ++i) {
            record.pop_back();
        }
    }

public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        vector<int> record;
        sort(candidates.begin(), candidates.end());
        dfs(res, candidates, record, 0, target);
        return res;
    }
};
