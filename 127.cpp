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
        if(beginWord.size() != endWord.size()) return false;
        if(beginWord.empty() && endWord.empty()) return true;
        if(wordList.empty()) return false;
        
        int dist = 1;
        queue<string> cur;
        queue<string> next;
        cur.push(beginWord);
        while(!wordList.empty() && !cur.empty()) {
            while(!cur.empty()) {
                string str = cur.front();
                cur.pop();
                for(int i = 0; i < str.size(); i++) {
                    char t = str[i];
                    for(char j = 'a'; j <= 'z'; j++) {
                        if(t == j) {
                            continue;
                        }
                        str[i] = j;
                        if(wordList.find(str) != wordList.end()) {
                            if(str == endWord) {
                                return dist + 1;
                            }
                            next.push(str);
                            wordList.erase(str);
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
