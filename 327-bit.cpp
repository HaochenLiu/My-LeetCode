/*
327. Count of Range Sum

Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

// Count of Range Sum

// Fenwick tree
class Solution {
    void add(vector<int> &fenwick, int n, int x) {
        for (; x < n; x |= x+1) {
            fenwick[x]++;
        }
    }
    int getSum(vector<int> &fenwick, int x) {
        int s = 0;
        for (; x; x &= x-1) {
            s += fenwick[x-1];
        }
        return s;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long s = 0, cnt = 0;
        vector<int> fenwick(n+1, 0);
        vector<long> scale;
        scale.push_back(0);
        for (int x: nums) {
            scale.push_back(s += x);
        }
        sort(scale.begin(), scale.end());
        s = 0;
        add(fenwick, n+1, lower_bound(scale.begin(), scale.end(), 0) - scale.begin());
        for (int x: nums) {
            s += x;
            cnt += getSum(fenwick, upper_bound(scale.begin(), scale.end(), s-lower) - scale.begin()) -
            getSum(fenwick, lower_bound(scale.begin(), scale.end(), s-upper) - scale.begin());
            add(fenwick, n+1, lower_bound(scale.begin(), scale.end(), s) - scale.begin());
        }
        return cnt;
    }
};
