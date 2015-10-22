/*
127. Word Ladder

Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if(beginWord.size() != endWord.size()) return 0;
        if(beginWord == endWord) return 1;
        unordered_set<string> s;
        queue<string> cur;
        queue<string> next;
        int dist = 2;

        wordList.insert(beginWord);
        wordList.insert(endWord);
        s.insert(beginWord);
        cur.push(beginWord);

        while(!cur.empty()) {
            while(!cur.empty()) {
                string str = cur.front();
                cur.pop();
                for(int i = 0; i < str.size(); i++) {
                    char t = str[i];
                    for(char c = 'a'; c <= 'z'; c++) {
                        if(c == t) continue;
                        str[i] = c;
                        if(wordList.find(str) != wordList.end() && s.find(str) == s.end()) {
                            if(str == endWord) {
                                return dist;
                            }
                            next.push(str);
                            s.insert(str);
                        }
                    }
                    str[i] = t;
                }
            }
            swap(cur, next);
            dist++;
        }

        return 0;
    }
};
