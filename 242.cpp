/*
242. Valid Anagram

Given two strings s and t, write a function to determine if t is an anagram of s.
For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
Note:
You may assume the string contains only lowercase alphabets.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if(len1!=len2){
            return false;
        }
        vector<int> count(26, 0);
        for(int i=0; i<len1; i++){
            count[s[i]-'a']++;
        }
        for(int i=0; i<len2; i++){
            if(--count[t[i]-'a']<0){
                return false;
            }
        }
        return true;
    }
};
