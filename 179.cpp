/*
179. Largest Number

Given a list of non negative integers, arrange them such that they form the largest number.
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
Note: The result may be very large, so you need to return a string instead of an integer.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0) return "";
        string str = "";

        while(!nums.empty()) {
                int idx1 = 0;
                for(int idx2 = 1; idx2 < nums.size(); idx2++) {
                if(to_string(nums[idx2]) + to_string(nums[idx1]) > to_string(nums[idx1]) + to_string(nums[idx2])) {
                    idx1 = idx2;
                }
            }
            str += to_string(nums[idx1]);
            nums.erase(nums.begin() + idx1);
        }
        while(str[0] == '0' && str.size() > 1) {
            str.erase(str.begin());
        }
        return str;
    }
};
