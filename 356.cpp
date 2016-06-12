/*
356. Line Reflection

Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given set of points.

Example 1:
Given points = [[1,1],[-1,1]], return true.

Example 2:
Given points = [[1,1],[-1,-1]], return false.

Follow up:
Could you do better than O(n2)?

Show Hint 
Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if(points.empty()) return true;
        int minx = INT_MAX;
        int maxx = INT_MIN;
        unordered_map<int, unordered_set<int> > dict;
        for(auto point : points){
            minx = min(minx, point.first);
            maxx = max(maxx, point.first);
            dict[point.first].insert(point.second);
        }
        int line = maxx + minx;

        for(auto it = dict.begin(); it != dict.end(); it++){
            int x = line - it->first;
            if(dict.find(x) == dict.end()) return false;
            for(auto jt = it->second.begin(); jt != it->second.end(); jt++){
                int y = *jt;
                if(dict[x].find(y) == dict[x].end()) return false;
            }
        }
        return true;
    }
};
