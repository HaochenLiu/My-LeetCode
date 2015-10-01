/*
060. Permutation Sequence

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

/*
Time: O(n)
Space: O(n)
Extra space: O(1)
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fac(n, 0);
        fac[0] = 1;
        for(int i = 1; i < n; ++i) {
            fac[i] = fac[i - 1] * i;
        }
        
        vector<int> ori;
        ori.clear();
        for(int i = 1; i <= n; ++i) {
            ori.push_back(i);
        }
        
        string str = "";
        for(int i = n - 1; i >= 0; --i) {
            int tmp = (k - 1) / fac[i];
            str += '0' + ori[tmp];
            ori.erase(ori.begin() + tmp);
            k -= tmp * fac[i];
        }
        return str;
    }
};
