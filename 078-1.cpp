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

/*
Time: O(2^n)
Space: O(2^n)
Extra space: O(n)
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> record;
        unsigned long long bitmax = (1<<n);
        sort(nums.begin(), nums.end());
        for(unsigned long long bit = 0; bit < bitmax; bit++) {
            record.clear();    
            for(int i = 0; i < n; i++) {
                if((bit>>i) & 1 == 1) {
                    record.push_back(nums[i]);
                }
            }
            res.push_back(record);
        }
        return res;
    }
};
