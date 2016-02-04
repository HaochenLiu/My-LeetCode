/*
018. 4Sum

http://www.cnblogs.com/TenosDoIt/p/3649607.html

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

/*
unordered_map
Time: O(n^2)
Space: O(n^2 + k)
Extra space: O(n^2)
k is number of solutions
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        res.clear();
        int n = num.size();
        sort(num.begin(), num.end());
        unordered_map<int, vector<pair<int, int>> > pairs;
        pairs.clear();
        
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j) {
                pairs[num[i] + num[j]].push_back(make_pair(i, j));
            }
        }
        
        for(int i = 0; i < n - 3; ++i) {
            if(i != 0 && num[i] == num[i - 1]) continue;
            for(int j = i + 1; j < n - 2; ++j) {
                if(j != i + 1 && num[j] == num[j - 1]) continue;
                if(pairs.find(target - num[i] - num[j]) != pairs.end()) {
                    vector<pair<int, int> > p = pairs[target - num[i] - num[j]];
                    bool first = true;
                    for(int k = 0; k < p.size(); ++k) {
                        if(p[k].first <= j) continue;
                        if(first || res.back()[2] != p[k].first) {
                            res.push_back(vector<int>{num[i], num[j], num[p[k].first], num[p[k].second]});
                            first = false;
                        }
                    }
                }
            }
        }
        auto pos = unique(res.begin(), res.end());
        res.erase(pos, res.end());
        return res;
    }
};
