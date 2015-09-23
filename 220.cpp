/*
220. Contains Duplicate III

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k. 
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k<1||t<0){
            return false;
        }
        unordered_map<int, long long> nums_map;
        queue<int> keys;
        int len = nums.size();
        for(int i=0; i<len; i++){
            int key = nums[i]/max(t, 1);
            for(int j=key-1; j<=key+1; j++){
                if(nums_map.find(j)!=nums_map.end() && abs(nums_map[j] - nums[i])<=(long long)t){
                    return true;
                }
            }
            nums_map[key]=nums[i];
            keys.push(key);
            if(nums_map.size()>k){
                nums_map.erase(keys.front());
                keys.pop();
            }
        }
        return false;
    }
};
