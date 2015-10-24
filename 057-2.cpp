/*
057. Insert Interval

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.empty()) {
            vector<Interval> res;
            res.push_back(newInterval);
            return res;
        }

        if(intervals.back().end < newInterval.start) {
            vector<Interval> res(intervals);
            res.push_back(newInterval);
            return res;
        }

        if(intervals[0].start > newInterval.end) {
            vector<Interval> res(intervals);
            res.insert(res.begin(), newInterval);
            return res;
        }
        
        int n = intervals.size();
        int beg = -1;
        if(intervals[0].end < newInterval.start) {
            int left = 0;
            int right = n - 1;
            while(left < right) {
                int mid = left + (right - left + 1) / 2;
                if(intervals[mid].end < newInterval.start) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            beg = left;
        }

        int end = n;
        if(intervals.back().start > newInterval.end) {
            int left = 0;
            int right = n - 1;
            while(left < right) {
                int mid = left + (right - left) / 2;
                if(intervals[mid].start > newInterval.end) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            end = left;
        }
        
        vector<Interval> res;
        for(int i = 0; i <= beg; i++) {
            res.push_back(intervals[i]);
        }
        
        if(beg == end - 1) {
            res.push_back(newInterval);
        } else {
            newInterval.start = min(newInterval.start, intervals[beg + 1].start);
            newInterval.end = max(newInterval.end, intervals[end - 1].end);
            res.push_back(newInterval);
        }

        for(int i = end; i < n; i++) {
            res.push_back(intervals[i]);
        }
        
        return res;
    }
};
