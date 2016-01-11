/*
327. Count of Range Sum My Submissions Question

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

// divide and conquer

class Solution {
    vector<long> a, b;
    int lower, upper;
    int f(int l, int h) {
        if (h-l <= 1) return 0;
        int m = l+h >> 1, cnt = f(l, m) + f(m, h), i = l, j = l;
        for (int k = m; k < h; k++) {
            while (i < m && a[i] < a[k]-upper) {
                i++;
            }
            while (j < m && a[j] <= a[k]-lower) {
                j++;
            }
            cnt += j - i;
        }
        merge(a.begin()+l, a.begin()+m, a.begin()+m, a.begin()+h, b.begin()+l);
        copy_n(b.begin()+l, h-l, a.begin()+l);
        return cnt;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;
        int n = nums.size();
        long s = 0;
        a.clear();
        a.push_back(0);
        for (int x: nums) {
            a.push_back(s += x);
        }
        b.resize(n+1);
        return f(0, n+1);
    }
};
