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

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        vector<int> record;
        res.clear();
        record.clear();
        if(numRows == 0) {
            return res;
        } else if(numRows == 1) {
            record.push_back(1);
            res.push_back(record);
            return res;
        } else {
            record.push_back(1);
            res.push_back(record);

            vector<int> tmp;
            for(int i = 1; i < numRows; i++) {
                tmp.clear();
                record = res[i - 1];
                tmp.push_back(1);
                for(int j = 1; j < i; j++) {
                    tmp.push_back(record[j - 1] + record[j]);
                }
                tmp.push_back(1);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
