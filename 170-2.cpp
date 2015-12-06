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

/*
Space: O(n^2)
Add Time: O(n)
Find Time: O(1)
*/

class TwoSum {
private:
    unordered_set<int> nums;
    unordered_set<int> sum;

public:
    void add(int number) {
        for (unordered_set<int>::const_iterator it = nums.begin(); it != nums.end(); it++) {
            sum.insert(number + *it);
        }
        nums.insert(number);
    }
   
    bool find(int value) {
        return sum.count(value) > 0;
    }
};

// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
