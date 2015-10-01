/*
090. Subsets II

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

/*
Time: O(2^n)
Space: O(2^n)
Extra space: O(n)
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, vector<int>{}, 0);
        sort(res.begin(), res.end());
        auto pos = unique(res.begin(), res.end());
        res.erase(pos, res.end());
        return res;
    }
};
