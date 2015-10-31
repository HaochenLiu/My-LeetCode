/*
149. Max Points on a Line

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if(n < 2) return n;
        int res = 0;
        for(int i = 0; i < n; i++) {
            int x = points[i].x;
            int y = points[i].y;
            int dup = 1;
            int vertical = 0;
            unordered_map<double, int> slope;
            for(int j = i + 1; j < n; j++) {
                if(points[j].x == x && points[j].y == y) {
                    dup++;
                } else if(points[j].y == y) {
                    vertical++;
                } else {
                    slope[(double)(points[j].x - x) / (double)(points[j].y - y)]++;
                }
            }

            for(auto it = slope.begin(); it != slope.end(); it++) {
                res = max(res, dup + it->second);
            }
            res = max(res, dup + vertical);
        }
        
        return res;
    }
};
