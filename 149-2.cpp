/*
149. Max Points on a Line

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/**
 * Definition for a point.mx
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int num = points.size();
        if(num <= 2) return num;
        
        map<int, int> mx;
        map<int, int> my;
        for(int i = 0; i < num; ++i) {
            mx[points[i].x]++;
            my[points[i].y]++;
        }
        
        int res = 2;
        for(int i = 0; i < num; ++i) {
            res = max(res, mx[points[i].x]);
            res = max(res, my[points[i].y]);
        }
        
        for(int i = 0; i < num - 1; ++i) {
            for(int j = i + 1; j < num; ++j) {
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;
                if(dx == 0 || dy == 0) continue;

                int cnt = 0;
                
                for(int k = 0; k < num; ++k) {
                    int nx = points[k].x - points[j].x;
                    int ny = points[k].y - points[j].y;
                    
                    if(nx * dy == dx * ny) {
                        cnt++;
                    }
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};
