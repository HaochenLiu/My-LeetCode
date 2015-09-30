/*
030. Substring with Concatenation of All Words

You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

/*
Time: O((nS-n*nL+1)*(n*nL))
Space: O(n*nL)
Extra space: O(n*nL)
nS is the length of S.
nL is the length of L.
n is number of strings in L.
*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        res.clear();
        int n = L.size();
        int len = L[0].size();
        if(n == 0 || len == 0) return res;
        if(S.length() < n * len) return res;
        
        map<string, int> m;
        for(int i = 0; i < n; ++i) {
            m[L[i]]++;
        }
        
        for(int i = 0; i <= S.length() - n * len; ++i) {
            map<string, int> t;
            bool flag = true;
            for(int j = i; j < i + n * len; j += len) {
                string tmp = S.substr(j, len);
                t[tmp]++;
                if(t[tmp] > m[tmp]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                res.push_back(i);
            }
        }
        return res;
    }
};
