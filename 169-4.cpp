/*
169. Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    int majorityElement(vector<int> &num) {//method 2
        map<int, int> mp;
        map<int, int>::iterator it;
        for(int i = 0; i < num.size(); i++) {
            it = mp.find(num[i]);
            if(it == mp.end()) {
                mp[num[i]] = 1;
            } else {
                it->second += 1;
            }
        }
        int max = mp.begin()->first;
        int maxcount = mp.begin()->second;
        for(it = mp.begin(); it != mp.end(); it++) {
            if(it->second > maxcount) {
                maxcount = it->second;
                max = it->first;
            }
        }
        return max;
    }
};
