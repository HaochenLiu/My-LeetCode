/*
254. Factor Combinations

Numbers can be regarded as product of its factors. For example,
8 = 2 x 2 x 2;
  = 2 x 4.


Write a function that takes an integer n and return all possible combinations of its factors.
Note:
Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples:
input: 1
output:
[]


input: 37
output:
[]


input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]


input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/

class Solution {
public:
    void getResult(vector<vector<int>>& res, vector<int>& record, int n){
        int i = record.empty() ? 2 : record.back();
        for(; i <= n / i; i++) {
            if(n % i == 0) {
                record.push_back(i);
                record.push_back(n / i);
                res.push_back(record);
                record.pop_back();
                getResult(res, record, n/i);
                record.pop_back();
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> record;
        getResult(res, record, n);
        return res;
    }
};
