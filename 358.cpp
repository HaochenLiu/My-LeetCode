/*
358. Rearrange String k Distance Apart

Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
str = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.
Example 2:
str = "aaabc", k = 3 

Answer: ""

It is not possible to rearrange the string.
Example 3:
str = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
*/

class Solution {
public:
    string rearrangeString(string str, int k) {
        if(k == 0)
            return str;
        unordered_map<char, int> times;
        queue<pair<char, int> > q;
        priority_queue<pair<char, int>, vector<pair<char, int> >, cmp> max_heap;
        pair<char, int> tmp;
        string result;
        for(int i = 0; i < str.size(); i++)
            times[str[i]]++;
        for(auto it = times.begin(); it != times.end(); it++)
            max_heap.push(make_pair(it->first, it->second));
        while(result.size() < str.size()) {
            if(q.size() == k) {
                tmp = q.front();
                q.pop();
                if(tmp.second != 0)
                    max_heap.push(tmp);
            }

            if(max_heap.empty())
                return "";
            tmp = max_heap.top();
            max_heap.pop();
            result = result + tmp.first;
            tmp.second--;
            q.push(tmp);
        }
        return result;
    }

private:
    class cmp {
    public:
        bool operator()(pair<char, int> a, pair<char, int> b) {
            if(a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        }
    };
};
