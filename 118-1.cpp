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
private:
    vector<vector<int> > ret;
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        
        for(int i = 0; i < numRows; i++)
        {
            if (i == 0)
            {
                vector<int> a;
                a.push_back(1);
                ret.push_back(a);
            }
            else
            {
                vector<int> a;
                for(int j = 0; j <= i; j++)
                    if (j == 0)
                        a.push_back(ret[i-1][j]);
                    else if (j == i)
                        a.push_back(ret[i-1][j-1]);
                    else
                        a.push_back(ret[i-1][j-1] + ret[i-1][j]);
                ret.push_back(a); 
            }
        }
        
        return ret;
    }
};
