/*
354. Russian Doll Envelopes

You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        auto Cmp = [](const pair<int, int> &a, const pair<int, int> &b) { 
            if(a.first < b.first) return true;
            if(a.first == b.first && a.second > b.second) return true;
            return false;
        };
        auto Cmp2 = [](const pair<int, int> &a, const pair<int, int> &b) { 
            return a.second < b.second;
        };
        sort(envelopes.begin(), envelopes.end(), Cmp);

        vector<pair<int, int>> res;
        for(int i=0; i<envelopes.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), envelopes[i], Cmp2);
            if(it == res.end()) res.push_back(envelopes[i]);
            else *it = envelopes[i];
        }
        return res.size();
    }
};
