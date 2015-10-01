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
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> record;
        res.push_back(record);
        sort(nums.begin(), nums.end());
        findSubsetsWithDup(nums, 0, record, res);
        return res;
    }
    
    void findSubsetsWithDup(vector<int> &nums, int start, vector<int> &record, vector<vector<int>>& res) {
        for(int i = start; i < nums.size(); i++) {
            if(i > start && nums[i] == nums[i-1]) {
                continue;
            }
            record.push_back(nums[i]);
            res.push_back(record);
            findSubsetsWithDup(nums, i + 1, record, res);
            record.pop_back();
        }
    }
};
