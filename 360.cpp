/*
360. Sort Transformed Array

Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
*/

class Solution {
    public:
        vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
            vector<int> res(nums.size());
            if (nums.size() == 0) return res;
            int i = 0, j = nums.size() - 1;
            if (a > 0) {
                int index = nums.size() - 1;
                while (i <= j) {
                    if (transform(nums[i], a, b, c) > transform(nums[j], a, b, c)) {
                        res[index--] = transform(nums[i], a, b, c);
                        i++;
                    } else {
                        res[index--] = transform(nums[j], a, b, c);
                        j--;
                    }
                }
            } else {
                int index = 0;
                while (i <= j) {
                    if (transform(nums[i], a, b, c) < transform(nums[j], a, b, c)) {
                        res[index++] = transform(nums[i], a, b, c);
                        i++;
                    } else {
                        res[index++] = transform(nums[j], a, b, c);
                        j--;
                    }
                }
            }
            return res;
        }

        int transform(int num, int a, int b, int c) {
            return a * num * num + b * num + c;
        }
};
