/*
287. Find the Duplicate Number My Submissions Question Solution 

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate element must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant extra space.
Your runtime complexity should be less than O(n2).
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
private:
    bool hasDup(vector<int>& num, int low, int high){
        int cnt = 0;
        for(int i = 0; i < num.size(); i++) {
            if(num[i] >= low && num[i] <= high) {
                cnt++;
            }
        }
        return (cnt > high - low + 1);
    }

public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        if(n <= 0) return 0;
        int low = 1;
        int high = n;
        while(low < high) {
            int mid = (low + high) / 2;
            if(hasDup(nums, low, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
