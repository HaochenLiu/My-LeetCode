/*
135. Candy

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?
*/

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);

        int k = 2;
        for(int i = 1; i < n ; i++){
            if(ratings[i] > ratings[i - 1]) {
                candy[i] = max(k, candy[i]);
                k++;
            } else {
                k = 2;
            }
        }

        k = 2;
        for(int i = n - 2; i >= 0 ; i--) {
            if(ratings[i] > ratings[i + 1]) {
                candy[i] = max(k, candy[i]);
                k++;
            } else {
                k = 2;
            }
        }

        int res = 0;
        for(int i = 0 ; i < n ; i++) {
            res += candy[i];
        }
         
        return res;
    }
};
