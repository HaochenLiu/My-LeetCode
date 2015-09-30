/*
046. Permutations

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

/*
Time: O(n!)
Space: O(n!)
Extra space: O(n)
*/

class Solution {
private:
    void dfs(vector<vector<int>>& res, vector<int>& record, vector<int>& nums, int index) {
        int size = nums.size();
        if(index == size) {
            res.push_back(record);
            return;
        }
        
        for(int i = index; i < size; i++) {
            swap(nums[index], nums[i]);
            record.push_back(nums[index]);
            dfs(res, record, nums, index + 1);
            record.pop_back();
            swap(nums[index], nums[i]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        vector<int> record;
        dfs(res, record, nums, 0);
        return res;
    }
};
