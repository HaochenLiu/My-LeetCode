/*
076. Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

class Solution {
private:
    bool isValid(int* exist) {
        bool flag = true;
        
        for(int i = 0; i < 256; i++) {
            if(exist[i] > 0) {
                flag = false;
                break;
            }
        }

        return flag;
    }

public:
    string minWindow(string s, string t) {
        if(s.size() < t.size() || t.size() == 0) return "";

        int exist[256];
        int beg = 0;
        int end = t.size() - 1;
        int record_beg = 0;
        int record_end = 0;
        int minWin = s.size() + 1;

        memset(exist, 0, sizeof(exist));
        for(int i = 0; i < t.size(); i++) {
            exist[t[i]]++;
            exist[s[i]]--;
        }
        
        if(isValid(exist)) {
            return s.substr(0, t.size());
        }
        
        while(beg <= end) {
            if(!isValid(exist)) {
                if(end == s.size() - 1) {
                    break;
                }
                end++;
                exist[s[end]]--;
            } else {
                if(end - beg < minWin) {
                    record_beg = beg;
                    record_end = end;
                    minWin = record_end - record_beg + 1;
                }
                exist[s[beg]]++;
                beg++;
            }
        }

        if(minWin != s.size() + 1) {
            return s.substr(record_beg, minWin);
        } else {
            return "";
        }
    }
};
