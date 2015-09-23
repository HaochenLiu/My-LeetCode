186. Reverse Words in a String II 

Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces and the words are always separated by a single space.
For example,
Given s = "the sky is blue",
return "blue is sky the".
Could you do it in-place without allocating extra space?
Related problem: Rotate Array

class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        string ret, word;
        
        for(int i = s.size() - 1; i >= 0; i--) {
            if(isspace(s[i])) {
                if(i < s.size()-1 && !isspace(s[i+1])) {
                    reverse(word.begin(),word.end());
                    ret.append(word+" ");
                    word.clear();
                }
            }
            else {
                word.push_back(s[i]);
            }
        }
        
        if(!isspace(s[0])) {
            reverse(word.begin(),word.end());
            ret.append(word);
        }
        else if(!ret.empty()) {
            ret.pop_back();
        }
            
        s = ret;
    }
};
