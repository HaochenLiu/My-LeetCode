/*
294. Flip Game II

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.
*/

class Solution {
private:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        int n = s.size();
        if(n < 2) return res;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1] && s[i] == '+') {
                s[i] = '-';
                s[i + 1] = '-';
                res.push_back(s);
                s[i] = '+';
                s[i + 1] = '+';
            }
        }
        
        return res;
    }
    
public:
    bool canWin(string s) {
        vector<string> v = generatePossibleNextMoves(s);
        if(v.empty()) {
            return false;
        }
        int n = v.size();
        for(int i = 0; i < n; i++) {
            if(!canWin(v[i])) {
                return true;
            }
        }

        return false;
    }
};
