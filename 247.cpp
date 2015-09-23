/*
247. Strobogrammatic Number II

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Find all strobogrammatic numbers that are of length = n.
For example,
Given n = 2, return ["11","69","88","96"].
Hint:
Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.
*/

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> strobos;
        if(n & 1) {
            strobos = {"0", "1", "8"};
        } else {
            strobos = {""};
        }
        vector<string> bases = {"00", "11", "88", "69", "96"};
        int m = bases.size();
        while(n > 1) {
            n -= 2;
            vector<string> temp;
            for(string strobo : strobos) {
                for(int i = (n < 2 ? 1 : 0); i < m; i++) {
                    temp.push_back(bases[i].substr(0, 1) + strobo + bases[i].substr(1));
                }
            }
            swap(temp, strobos);
        }
        return strobos;
    }
};
