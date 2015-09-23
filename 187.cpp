/*
187. Repeated DNA Sequences

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].


A: 1,000,001
C: 1,000,011
G: 1,000,111
T: 1,001,010
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> res;
        unordered_map<int, int> m;
        if(n <= 10) return res;
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            tmp = ((tmp << 3) | (s[i] & 7)) & 0x3FFFFFFF;
            if(m[tmp] == 1) {
                res.push_back(s.substr(i - 9, 10));
            }
            m[tmp]++;
        }
        return res;
    }
};
