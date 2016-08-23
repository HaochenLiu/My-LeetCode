/*
379. Design Phone Directory

Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);
*/

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        upbnd = maxNumbers - 1;
        used.resize(maxNumbers + 1, false);
        dict.resize(maxNumbers + 1);
         fnt = rear = 0;
        for(int i = 0; i < maxNumbers; ++ i)
            dict[rear ++] = i;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(fnt >= rear)
            return -1;
        int res = dict[fnt ++];
        used[res] = true;
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if(number < 0 || number > upbnd)
            return false;
        return !used[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(number >= 0 && number <= upbnd && used[number]){
            used[number] = false;
            dict[-- fnt] = number;
        }
    }
private:
    vector<int> dict;
    vector<bool> used;
    int upbnd, fnt, rear;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
