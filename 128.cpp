/*
128. Longest Consecutive Sequence

http://www.cnblogs.com/x1957/archive/2013/08/22/3274274.html
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

/*
Time: O(n)
Space: O(n)
Extra space: O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s;
        int res = 0;
        for (int i = 0; i < num.size(); i++) {
            s.insert(num[i]);
        }
        for (int i = 0; i < num.size() && !s.empty(); i++) {
            if (s.find(num[i]) == s.end()) {
                continue;
            }
            int upper = num[i], lower = num[i];
            while (s.find(upper + 1) != s.end()) {
                s.erase(++upper);
            }
            while (s.find(lower - 1) != s.end()) {
                s.erase(--lower);
            }
            if (upper != lower) {
                s.erase(num[i]);
            }
            res = max(res, upper - lower + 1);
        }
        return res;
    }
};
