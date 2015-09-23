/*
134. Gas Station
http://www.cnblogs.com/xinsheng/p/3515024.html

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() == 0) return -1;
        int n = gas.size();
        int sum = 0;
        int minIdx = -1;
        int minVal = INT_MAX;
        for(int i = 0; i < n; i++) {
            gas[i] -= cost[i];
            sum += gas[i];
            if(sum <= minVal) {
                minIdx = i;
                minVal = sum;
            }
        }
        if(sum < 0) {
            return -1;
        }
        return (minIdx + 1) % n;
    }
};
