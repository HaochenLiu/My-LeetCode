/*
118. Pascal's Triangle

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

/*
Time: O(2^n)
Space: O(2^n)
Extra space: O(n)
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++) {
            if (i == 0) {
                vector<int> record;
                record.push_back(1);
                res.push_back(record);
            } else {
                vector<int> record;
                for(int j = 0; j <= i; j++) {
                    if (j == 0) {
                        record.push_back(res[i - 1][j]);
                    } else if (j == i) {
                        record.push_back(res[i - 1][j - 1]);
                    } else {
                        record.push_back(res[i - 1][j - 1] + res[i - 1][j]);
                    }
                }
                res.push_back(record); 
            }
        }
        
        return res;
    }
};
