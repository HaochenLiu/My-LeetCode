/*
275. H-Index II

Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
Hint:
Expected runtime complexity is in O(log n) and the input is sorted.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int res = 0;
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());
        for(int i = 0; i < n; i++) {
            res = max(res, min(i + 1, citations[i]));
        }
        return res;
    }
};
