/*
072. Edit Distance

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > f(word1.size()+1, vector<int>(word2.size()+1));
        f[0][0] = 0;
        for(int i = 1; i <= word2.size(); i++) {
            f[0][i] = i;
        }
        
        for(int i = 1; i <= word1.size(); i++) {
            f[i][0] = i;
        }
            
        for(int i = 1; i <= word1.size(); i++) {
            for(int j = 1; j <= word2.size(); j++) {
                f[i][j] = INT_MAX;
                if (word1[i - 1] == word2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                }
                
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
                f[i][j] = min(f[i][j], min(f[i - 1][j], f[i][j - 1]) + 1);
            }
        }
            
        return f[word1.size()][word2.size()];
    }
};
