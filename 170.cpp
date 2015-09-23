/*
170. Two Sum III - Data structure design 

Design and implement a TwoSum class. It should support the following operations: add and find.
add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.
For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
*/

class TwoSum {
private:
    unordered_map<int, int> map;

public:
    void add(int number) {
        map[number]++;
    }
   
    bool find(int value) {
        for (unordered_map<int, int>::const_iterator it = map.begin(); it != map.end(); it++) {
            int key = value - it->first;
            if (key == it->first) {
                if (it->second >= 2) {
                    return true;
                }
            } else {
                if (map.find(key) != map.end()) {
                    return true;
                }
            }
        }
        return false;
    }
};
