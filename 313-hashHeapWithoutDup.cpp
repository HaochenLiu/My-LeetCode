/*
313. Super Ugly Number

Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.

Credits:
Special thanks to @peisi for adding this problem and creating all test cases.
*/

class HHeapMinWithoutDup {
private:
    int A[1000000];
    int __size;
    unordered_map<int, int> h;

public:
    HHeapMinWithoutDup() {
        h.clear();
        memset(A, 0, sizeof(A));
        __size = 0;
    }
    
    void check() {
        cout<<"size: "<<__size<<endl;
        cout<<"[";
        for(int i = 0; i < __size - 1; i++) {
            cout<<A[i]<<", ";
        }
        cout<<A[__size - 1]<<"]"<<endl;
    }
    
    int size() {
        return __size;
    }

    void push(int n) {
        if(h.find(n) != h.end()) return;
        h[n] = __size;
        A[__size] = n;
        __size++;
        int i = __size - 1;
        while(i > 0) {
            int j = (i - 1) / 2;
            if(A[j] > A[i]) {
                h[A[i]] = j;
                h[A[j]] = i;
                swap(A[j], A[i]);
                i = j;
            } else {
                break;
            }
        }
        return;
    }
    
    int top() {
        return A[0];
    }
    
    void pop() {
        h.erase(A[0]);
        h[A[__size - 1]] = 0;
        A[0] = A[__size - 1];
        __size--;
        int i = 0;
        while(2 * i + 1 < __size) {
            int minIdx = i;
            if(A[2 * i + 1] < A[minIdx]) {
                minIdx = 2 * i + 1;
            }
            if(2 * i + 2 < __size && A[2 * i + 2] < A[minIdx]) {
                minIdx = 2 * i + 2;
            }
            if(minIdx == i) {
                break;
            }
            h[A[i]] = minIdx;
            h[A[minIdx]] = i;
            swap(A[i], A[minIdx]);
            i = minIdx;
        }
        return;
    }
    
    void erase(int n) {
        if(__size == 0) return;
        if(h.find(n) == h.end()) {
            return;
        }
        int i = h[n];
        if(A[__size - 1] == n) {
            h.erase(n);
            __size--;
            return;
        } else if(A[__size - 1] > n) {
            h.erase(A[i]);
            h[A[__size - 1]] = i;
            A[i] = A[__size - 1];
            __size--;
            while(2 * i + 1 < __size) {
                int minIdx = i;
                if(A[2 * i + 1] < A[minIdx]) {
                    minIdx = 2 * i + 1;
                }
                if(2 * i + 2 < __size && A[2 * i + 2] < A[minIdx]) {
                    minIdx = 2 * i + 2;
                }
                if(minIdx == i) {
                    break;
                }
                h[A[i]] = minIdx;
                h[A[minIdx]] = i;
                swap(A[i], A[minIdx]);
                i = minIdx;
            }
            return;
        } else {
            h.erase(i);
            h[A[__size - 1]] = i;
            A[i] = A[__size - 1];
            __size--;
            while(i > 0) {
                int j = (i - 1) / 2;
                if(A[j] > A[i]) {
                    h[A[i]] = j;
                    h[A[j]] = i;
                    swap(A[j], A[i]);
                    i = j;
                } else {
                    break;
                }
            }
            return; 
        }
    }
    
    bool find(int n) {
        if(__size == 0 || n < A[0]) return false;
        return (h.find(n) != h.end());
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        HHeapMinWithoutDup heap;
        heap.push(1);
        for(int j = 0; j < k; j++) {
            heap.push(primes[j]);
        }

        for(int i = 0; i < n - 1; i++) {
            int t = heap.top();
            heap.pop();
            for(int j = 0; j < k; j++) {
                heap.push(t * primes[j]);
            }
        }
        return heap.top();
    }
};
