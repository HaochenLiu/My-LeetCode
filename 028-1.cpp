/*
028. Implement strStr()
http://blog.csdn.net/yaochunnian/article/details/7059486
O(n)  

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button to reset your code definition.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        while (haystack[i] && needle[j]) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                i = i - j + 1;
                j = 0;
            }
        }
        return (needle[j] ? -1 : i - j);
    }
};
