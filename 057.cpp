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

/*
Time: O(n)
Space: O(n)
Extra space: O(1)
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
private:
    vector<Interval> ret;
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        bool inserted = false;
        if (intervals.size() == 0) {
            inserted = true;
            ret.push_back(newInterval);
        }

        int i = 0;
        while (i < intervals.size()) {
            if (ret.size() == 0) {
                if (intervals[i].start < newInterval.start) {
                    ret.push_back(intervals[i]);
                    i++;
                } else {
                    inserted = true;
                    ret.push_back(newInterval);
                }
            } else {
                int size = ret.size();
                if (inserted)
                {
                    if (ret[size-1].start <= intervals[i].start && intervals[i].start <= ret[size-1].end)
                        ret[size-1].end = max(ret[size-1].end, intervals[i].end);
                    else
                        ret.push_back(intervals[i]);
                    i++;
                } else {
                    if (newInterval.start < intervals[i].start) {
                        inserted = true;
                        if (ret[size-1].start <= newInterval.start && newInterval.start <= ret[size-1].end) {
                            ret[size-1].end = max(ret[size-1].end, newInterval.end);
                        } else {
                            ret.push_back(newInterval);
                        }
                    } else {
                        if (ret[size-1].start <= intervals[i].start && intervals[i].start <= ret[size-1].end) {
                            ret[size-1].end = max(ret[size-1].end, intervals[i].end);
                        } else {
                            ret.push_back(intervals[i]);
                        }
                        i++;
                    }
                }
            }
        }
            
        if (!inserted) {
            int size = ret.size();
            if (ret[size-1].start <= newInterval.start && newInterval.start <= ret[size-1].end) {
                ret[size-1].end = max(ret[size-1].end, newInterval.end);
            } else {
                ret.push_back(newInterval);
            }
        }
            
        return ret;           
    }
};
