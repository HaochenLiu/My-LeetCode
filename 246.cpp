/*
246. Strobogrammatic Number

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Write a function to determine if a number is strobogrammatic. The number is represented as a string.
For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/

class Solution {
private:
    bool isStroPair(char a, char b) {
        if(a == '0' && b == '0') return true;
        if(a == '1' && b == '1') return true;
        if(a == '6' && b == '9') return true;
        if(a == '8' && b == '8') return true;
        if(a == '9' && b == '6') return true;
        return false;
    }

public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        if(n == 0) return true;
        if(n == 1) return isStroPair(num[0], num[0]);
        for(int i = 0; i < (n + 1) / 2; i++) {
            if(!isStroPair(num[i], num[n - 1 - i])) {
                return false;
            }
        }
        return true;
    }
};
