/*
028. Implement strStr()
http://blog.csdn.net/yaochunnian/article/details/7059486

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button to reset your code definition.

KMP
O(n+m)
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int sLen = haystack.size();
        int pLen = needle.size();
        int i = 0;
        int j = 0;
        vector<int> next(pLen, -1);
        GetNextval(needle, next);
        while (i < sLen && j < pLen) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j == pLen) {
            return i - j;
        } else {
            return -1;
        }
    }
    
    void GetNextval(string p, vector<int>& next) {
        int pLen = p.size();
        next[0] = -1;
        int k = -1;
        int j = 0;
        while (j < pLen - 1) {
            if (k == -1 || p[j] == p[k]) {
                j++;
                k++;
                if (p[j] != p[k]) {
                    next[j] = k;
                } else {
                    next[j] = next[k];
                }
            } else {
                k = next[k];
            }
        }
    }
};
