/*
295. Find Median from Data Stream

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2
*/

/*
less 大顶堆
greater 小顶堆
*/

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int> > small;
    priority_queue<int, vector<int>, greater<int> > large;
    
public:
    MedianFinder() {
        small.push(INT_MIN);
        large.push(INT_MAX);
    }
    
    // Adds a number into the data structure.
    void addNum(int num) {
        if((small.size() + large.size()) & 1) {
            large.push(num);
        } else {
            small.push(num);
        }

        int vs = small.top();
        int vl = large.top();
        if(vs > vl) {
            small.pop();
            small.push(vl);
            large.pop();
            large.push(vs);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if((small.size() + large.size()) & 1) {
            return (double)small.top();
        } else {
            return (small.top() + large.top()) / 2.0;
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
