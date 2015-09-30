/*
017. Letter Combinations of a Phone Number

Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

/*
Time: O(4^n)
Space: O(4^n)
Extra space: O(4^(n-1))
n is the lenght of digits
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string str[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int len[8];
        for(int i = 0; i < 8; ++i) {
            len[i] = str[i].size();
        }
        
        vector<string> res;
        vector<string> tmp;
        res.clear();
        res.push_back("");
        tmp.clear();
        tmp.push_back("");
        for(int i = 0; i < digits.size(); ++i) {
            tmp = res;
            res.clear();
            int pos = digits[i] - '2';
            for(int j = 0; j < tmp.size(); ++j) {
                for(int k = 0; k < len[pos]; ++k) {
                    res.push_back(tmp[j] + str[pos][k]);
                }
            }
        }
        return res;
    }
};
