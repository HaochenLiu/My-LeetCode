/*
001. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
*/

/*
Time: O(n)
Space: O(n+k)
Extra space: O(n)
k is number of solutions.
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();
        unordered_map<int, int> m;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(m.find(target - numbers[i]) != m.end()) {
                res.push_back(m[target - numbers[i]]);
                res.push_back(i);
                return res;
            } else {
                m[numbers[i]] = i;
            }
        }
    }
};
