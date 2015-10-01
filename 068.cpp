/*
068. Text Justification

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Note: Each word is guaranteed not to exceed L in length.
*/

class Solution {
private:
    vector<string> ret;
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        ret.clear();
        int i = 0;
        while(i < words.size()) {
            int size = 0;
            int beg = i;
            while(i < words.size()) {
                int newSize = size == 0 ? words[i].size() : size + 1 + words[i].size();
                if (newSize <= L) {
                    size = newSize;
                }
                else {
                    break;
                }
                i++;
            }
            
            int spaceCount = L - size;
            int everyCount;
            if (i - 1 - beg != 0 && i != words.size()) {
                everyCount = spaceCount / (i - 1 - beg);
                spaceCount %= (i - 1 - beg);
            } else {
                everyCount = 0;
            }
            string s;
            for(int j = beg; j < i; j++) {
                if (j == beg) {
                    s = words[j];
                } else {
                    s += ' ';
                    for(int k = 0; k < everyCount; k++) {
                        s += ' ';
                    }
                    
                    if (spaceCount > 0 && i != words.size()) {
                        s += ' ';
                        spaceCount--;
                    }
                    s += words[j];
                }
            }
                
            for(int j = 0; j < spaceCount; j++) {
                s += ' ';
            }
                
            ret.push_back(s);
        }
        return ret;
    }
};
