/*
303. Range Sum Query - Immutable

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

class NumArray {
private:
    vector<int> sum;
    
public:
    NumArray(vector<int> &nums) {
        int t = 0;
        sum.push_back(t);
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            t += nums[i];
            sum.push_back(t);
        }
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
