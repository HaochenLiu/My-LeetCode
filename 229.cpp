/*
229. Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
Hint:
How many majority elements could it possibly have?
Do you have a better hint? Suggest it!
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        
        int len = nums.size();
        int can1 = 0;
        int can2 = 0;
        int count1 = 0;
        int count2 = 0;

        for(int i=0; i<len; i++) {
            if(count1 == 0 && count2 == 0) {
                can1 = nums[i];
                count1 = 1;
            } else if(count1 != 0 && count2 != 0 && can1 != nums[i] && can2 != nums[i]) {
                count1--;
                count2--;
            } else if(can1 == nums[i] && count1 != 0) {
                count1++;
            } else if(can2 == nums[i] && count2 != 0) {
                count2++;
            } else if(count1 == 0 && count2 != 0 && can2 != nums[i]) {
                can1 = nums[i];
                count1++;
            } else if(count2 == 0 && count1 != 0 && can1 != nums[i]) {
                can2 = nums[i];
                count2++;
            }
        }
        
        if(count1!=0){
            count1 = 0;
            for(int i = 0; i < len; i++){
                if(can1 == nums[i]) {
                    count1++;
                }
            }
            if(count1 > len / 3) {
                result.push_back(can1);
            }
        }
        if(count2 != 0) {
            count2 = 0;
            for(int i = 0; i < len; i++) {
                if(can2 == nums[i]) {
                    count2++;
                }
            }
            if(count2 > len / 3) {
                result.push_back(can2);
            }
        }
        
        return result;
    }
};
