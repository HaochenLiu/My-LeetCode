/*
047. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

/*
Time: O(n!)
Space: O(n!)
Extra space: O(n)
*/

class Solution {
private:
public:
    void dfs(vector<vector<int>>& res, vector<int>& record, vector<int>& nums, vector<bool>& canUse, int dep, int maxDep) {
        if (dep == maxDep) {
            res.push_back(record);
            return;
        }
        
        for(int i = 0; i < maxDep; i++) {
            if (canUse[i]) {
                if (i != 0 && nums[i] == nums[i - 1] && canUse[i - 1]) {
                    continue;
                }
                canUse[i] = false;
                record.push_back(nums[i]);
                dfs(res, record, nums, canUse, dep + 1, maxDep);
                record.pop_back();
                canUse[i] = true;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        vector<int> record;
        vector<bool> canUse(nums.size(), true);
        sort(nums.begin(), nums.end());
        dfs(res, record, nums, canUse, 0, nums.size());
        return res;
    }
};
