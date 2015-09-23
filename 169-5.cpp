/*
169. Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int, int> mp;
        map<int, int>::iterator it;
        for(int i = 0; i < num.size(); i++) {
            it = mp.find(num[i]);
            if(it == mp.end()) {
                mp[num[i]] = 1;
                if(1 > num.size()/2) {
                    return num[i];
                }
            } else {
                it->second += 1;
                if(it->second > num.size()/2) {
                    return it->first;
                }
            }
        }
    }
};
