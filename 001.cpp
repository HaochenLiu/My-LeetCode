/*
001. Two Sum

Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
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
                res.push_back(i + 1);
                return res;
            } else {
                m[numbers[i]] = i + 1;
            }
        }
    }
};
