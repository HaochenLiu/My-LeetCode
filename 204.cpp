/*
204. Count Primes

Description:
Count the number of prime numbers less than a non-negative number, n
click to show more hints.
References:
How Many Primes Are There?
Sieve of Eratosthenes
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        bool isPrime[n];
        memset(isPrime, true, sizeof(isPrime));
        isPrime[1] = false;
        for(int i = 2; i < n; i++) {
            if(!isPrime[i]) continue;
            for(int j = i * 2; j < n; j += i) {
                isPrime[j] = false;
            }
        }

        for(int i = 2; i < n; i++) {
            if(isPrime[i]) {
                res++;
            }
        }
        
        return res;
    }
};
