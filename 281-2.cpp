/*
281. Zigzag Iterator

Given two 1d vectors, implement an iterator to return their elements alternately.
For example, given two 1d vectors:
v1 = [1, 2]
v2 = [3, 4, 5, 6]


By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].
Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
*/

/*
ZigzagIterator(vector<int>& v1, vector<int>& v2) {}
Time: O(1)
Space: O(1)
Extra space: O(1)

int next() {}
Time: O(1)
Space: O(1)
Extra space: O(1)

bool hasNext() {}
Time: O(1)
Space: O(1)
Extra space: O(1)
*/

class ZigzagIterator {
    int idx;
    vector<int> vec1;
    vector<int> vec2;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        idx = 0;
        vec1 = v1;
        vec2 = v2;
    }
 
    int next() {
        int res;
        if(idx / 2 < min(vec1.size(), vec2.size())) {
            if(idx % 2 == 0) {
                res = vec1[idx / 2];
            } else {
                res = vec2[idx / 2];
            }
        } else {
            if(vec1.size() < vec2.size()) {
                res = vec2[idx - vec1.size()];
            } else {
                res = vec1[idx - vec2.size()];
            }
        }
        idx++;
        return res;
    }
 
    bool hasNext() {
        return (idx < vec1.size() + vec2.size());
    }
};
 
/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
