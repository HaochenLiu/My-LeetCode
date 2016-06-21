/*
362. Design Hit Counter

Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:
HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301); 
Follow up:
What if the number of hits per second could be very large? Does your design scale?

Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
*/

class HitCounter {
public:
    // A queue of pairs, (timestamp, numbers of hit).
    queue<pair<int, int>> rec;
    int hit_count;

    /** Initialize your data structure here. */
    HitCounter() {
        hit_count = 0;
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        // Once we receive the timestamp, we should add hit to rec, and remove out-timed ones

        // First, remove out-timed ones
        while(!rec.empty() && timestamp - rec.front().first >= 300) {
            hit_count -= rec.front().second; // remove hit count
            rec.pop();
        }

        // Check if current back has same timestamp as this new hit
        if(!rec.empty() && rec.back().first == timestamp) {
            // Just add hit_counts at this timestamp
            rec.back().second += 1;
            hit_count += 1;
        }
        else {
            // Create a new timestamp
            rec.push(make_pair(timestamp, 1));
            hit_count += 1;
        }

    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        // First, remove out-timed ones
        while(!rec.empty() && timestamp - rec.front().first >= 300) {
            hit_count -= rec.front().second; // remove hit count
            rec.pop();
        }

        return hit_count;
    }
}; 

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
