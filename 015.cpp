/*
015. 3Sum
http://tech-wonderland.net/blog/summary-of-ksum-problems.html
http://blog.unieagle.net/2012/08/22/leetcode%E9%A2%98%E7%9B%AE3sum/
http://www.cnblogs.com/TenosDoIt/p/3649607.html

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

O(n^2)
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        res.clear();
        if(num.size() < 3) return res;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); ++i) {
            if(num[i] > 0) break;
            if(i != 0 && num[i - 1] == num[i]) continue;
            int target = -num[i];
            int j = i + 1;
            int k = num.size() - 1;
            while(j < k) {
                if(num[j] + num[k] == target) {
                    res.push_back(vector<int>{num[i], num[j], num[k]});
                    j++;
                    while(j < k && num[j - 1] == num[j]) j++;
                    k--;
                    while(j < k && num[k + 1] == num[k]) k--;
                    continue;
                } else if(num[j] + num[k] > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        
        sort(res.begin(), res.end());
        auto pos = unique(res.begin(), res.end());
        res.erase(pos, res.end());
        return res;
    }
};
