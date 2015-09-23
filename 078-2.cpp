/*
078. Subsets

Given a set of distinct integers, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
private:
    vector<vector<int>> res;
    
    void dfs(vector<int>& nums, vector<int> record, int start) {
        res.push_back(record);
        for(int i = start; i < nums.size(); i++) {
            vector<int> record2(record);
            record2.push_back(nums[i]);
            dfs(nums, record2, i + 1);
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, vector<int>{}, 0);
        return res;
    }
};
