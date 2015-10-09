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
        if(beginWord.empty() || endWord.empty()) return 1;
        if(wordList.size() == 0) return 0;

        int distance = 1;
        queue<string> queToPush;
        queue<string> queToPop;
        queToPop.push(beginWord);
        while(wordList.size() > 0 && !queToPop.empty()) {
            while(!queToPop.empty()) {
                string str(queToPop.front());
                queToPop.pop();
                for(int i = 0; i < str.size(); i++) {
                    for(char j = 'a'; j <= 'z'; j++) {
                        if(j == str[i]) {
                            continue;
                        }
                        char temp = str[i];
                        str[i] = j;
                        if(str == endWord) {
                            return distance + 1;
                        }
                        if(wordList.find(str) != wordList.end()) {
                            queToPush.push(str);
                            wordList.erase(str);
                        }
                        str[i] = temp;
                    }
                }
            }
            swap(queToPush, queToPop);
            distance++;
        }
        return 0;
    }
};
