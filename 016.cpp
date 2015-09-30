/*
016. 3Sum Closest

http://www.cnblogs.com/TenosDoIt/p/3649607.html

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
    For example, given array S = {-1 2 1 -4}, and target = 1.
    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

/*
Time: O(n^2)
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size() < 3) return 0;
        int res = num[0] + num[1] + num[2];
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); ++i) {
            if(i != 0 && num[i - 1] == num[i]) continue;
            int j = i + 1;
            int k = num.size() - 1;
            while(j < k) {
                if(num[i] + num[j] + num[k] == target) {
                    return target;
                } else if(num[i] + num[j] + num[k] > target) {
                    if(abs(num[i] + num[j] + num[k] - target) < abs(res - target)) {
                        res = num[i] + num[j] + num[k];
                    }
                    k--;
                } else {
                    if(abs(num[i] + num[j] + num[k] - target) < abs(res - target)) {
                        res = num[i] + num[j] + num[k];
                    }
                    j++;
                }
            }
        }
        return res;
    }
};
