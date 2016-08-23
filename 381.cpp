/*
381. Insert Delete GetRandom O(1) - Duplicates allowed

Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
*/

class RandomizedCollection {
private:
    unordered_map<int,unordered_set<int>> valtonum;
    vector<int> numtoval;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        int k=numtoval.size();
        numtoval.push_back(val);
        valtonum[val].insert(k);
        return valtonum[val].size() == 1;
    }  

    bool remove(int val) {
        if(valtonum[val].empty())return false;
        int num=*valtonum[val].begin();
        numtoval[num]=numtoval.back();
        valtonum[val].erase(num);
        valtonum[numtoval.back()].insert(num);
        valtonum[numtoval.back()].erase(numtoval.size()-1);
        numtoval.pop_back();
        return true;
    }

    int getRandom() {
        return numtoval[rand()%numtoval.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
 
