/*
179. Largest Number
Given a list of non negative integers, arrange them such that they form the largest number.
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
Note: The result may be very large, so you need to return a string instead of an integer.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

bool comp(string a, string b) {
    return ((a + b) < (b + a));
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0) return "";
        int n = nums.size();
        vector<string> str;
        string res = "";
        for(int i = 0; i < n; i++) {
            str.push_back(to_string(nums[i]));
        }
        sort(str.begin(), str.end(), comp);
        for(int i = n - 1; i >= 0; i--) {
            res += str[i];
        }
        while(res.size() > 1 && res[0] == '0') {
            res.erase(res.begin());
        }
        return res;
    }
};
