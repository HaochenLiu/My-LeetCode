/*
163. Missing Ranges

Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.
For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

class Solution {
private:
    string get_range(int low, int high) {
        char tmp[10];
        if (low == high) {
            sprintf(tmp, "%d", low);
        } else {
            sprintf(tmp, "%d->%d", low, high);
        }
        return string(tmp);
    }

public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int n = nums.size();
        nums.insert(nums.begin(), lower - 1);
        nums.push_back(upper + 1);
        for (int i = 1; i <= n + 1; i++) {
            if (nums[i] - nums[i - 1] > 1) {
                res.push_back(get_range(nums[i - 1] + 1, nums[i] - 1));
            }
        }
        return res;
    }
};
