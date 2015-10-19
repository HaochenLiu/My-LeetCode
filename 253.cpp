/*
253. Meeting Rooms II

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        int n = intervals.size();
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[intervals[i].start]++;
            m[intervals[i].end]--;
        }
        
        int res = 0;
        int cur = 0;
        for(auto it = m.begin(); it != m.end(); it++) {
            cur += it->second;
            res = max(res, cur);
        }
        
        return res;
    }
};
