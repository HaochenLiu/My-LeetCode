/*
018. 4Sum
http://www.cnblogs.com/TenosDoIt/p/3649607.html

O(n^3)

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        res.clear();
        if(num.size() < 4) return res;
        sort(num.begin(), num.end());
        int n = num.size();
        for(int i = 0; i < n - 3; ++i) {
            if(i != 0 && num[i - 1] == num[i]) continue;
            for(int j = i + 1; j < n - 2; ++j) {
                if(j != i + 1 && num[j - 1] == num[j]) continue;
                int k = j + 1;
                int l = n - 1;
                int tmp = target - num[i] - num[j];
                while(k < l) {
                    if(num[k] + num[l] == tmp) {
                        res.push_back(vector<int>{num[i], num[j], num[k], num[l]});
                        k++;
                        while(k < l && num[k - 1] == num[k]) k++;
                        l--;
                        while(k < l && num[l + 1] == num[l]) l--;
                    } else if(num[k] + num[l] > tmp) {
                        l--;
                    } else {
                        k++;
                    }
                }
            }
        }
        auto pos = unique(res.begin(), res.end());
        res.erase(pos, res.end());
        return res;
    }
};
