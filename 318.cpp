/*
318. Maximum Product of Word Lengths

Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:

Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:

Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:

Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

Follow up:
Could you do better than O(n2), where n is the number of words?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> bitWords(n, 0);
        size_t maxLenProd = 0;
    
        for(int i=0; i<n; ++i){
            for(int j=0; j<words[i].length(); ++j){
                bitWords[i] |= (1<<(words[i][j]-'a'));
            }
        }
    
        for(int i=0; i<n-1; ++i){
            for(int j=i+1; j<n; ++j){
                if((bitWords[i]&bitWords[j]) == 0){
                    maxLenProd = max(maxLenProd, words[i].length()*words[j].length());
                }
            }
        }

        return maxLenProd;    
    }
};
