/*
252. Meeting Rooms

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
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

bool comp(Interval a, Interval b) {
    return a.start < b.start;
}
    
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n < 2) return true;
        sort(intervals.begin(), intervals.end(), comp);
        for(int i = 1; i < n; i++) {
            if(intervals[i - 1].end > intervals[i].start) {
                return false;
            }
        }

        return true;
    }
};
