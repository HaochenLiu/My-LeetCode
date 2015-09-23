/*
096. Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

  1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> cnt{1, 1, 2};
        if(n <= 2) return cnt[n];

        for(int i = 3; i <= n; i++) {
            int res = 0;
            for(int j = 1; j <= i; j++) {
                res += cnt[j - 1] * cnt[i - j];
            }
            cnt.push_back(res);
        }
        
        return cnt[n];
    }
};
