/*
363. Max Sum of Rectangle No Larger Than K

Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.
*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()||matrix[0].empty()) return 0;
        int rsz=matrix.size(),csz=matrix[0].size();
        if (matrix[0][0]==k) return k;
        vector<vector<int>> sums=matrix;
        int maxSum=INT_MIN;
        int temp;
        for (int i=1;i<rsz;i++){
            sums[i][0]+=sums[i-1][0];
        }
        for (int j=1;j<csz;j++){
            sums[0][j]+=sums[0][j-1];
        }
        for (int i=1;i<rsz;i++)
        for (int j=1;j<csz;j++){
            sums[i][j]+=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
        }
    
        for (int cl=0;cl<csz;cl++){
            for (int cr=cl;cr<csz;cr++){
                set<int> area;
                set<int>::iterator iter;
                int curArea;
                area.insert(0);
                for (int rd=0;rd<rsz;rd++){
                    curArea=sums[rd][cr]-(cl==0?0:sums[rd][cl-1]);
                    iter=area.lower_bound(curArea-k);
                    if (iter!=area.end()){
                        maxSum = max(maxSum,curArea-(*iter));
                        if (maxSum==k) return k;
                    }
                    area.insert(curArea);
                }
            }
        }
        return maxSum;  
    }
};
