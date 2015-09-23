/*
241. Different Ways to Add Parentheses

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1
Input: "2-1-1".
((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]

Example 2
Input: "2*3-4*5"
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        
        int len = input.length();
        if(len == 0){
            return result;
        }
        
        if(isInt(input)){
            result.push_back(std::stoi(input));
            return result;
        }
        
        for(int i=0; i<len; i++){
            if(input[i]<'0' || input[i]>'9'){
                vector<int> leftResult = diffWaysToCompute(input.substr(0, i));
                vector<int> rightResult = diffWaysToCompute(input.substr(i+1));
                for(int m = 0; m<leftResult.size(); m++){
                    for(int n = 0; n<rightResult.size(); n++){
                        switch(input[i]){
                            case '+':
                                result.push_back(leftResult[m] + rightResult[n]);
                                break;
                            case '-':
                                result.push_back(leftResult[m] - rightResult[n]);
                                break;
                            case '*':
                                result.push_back(leftResult[m] * rightResult[n]);
                                break;
                        }
                    }
                }
            }
        }
        
        return result;
    }
    
    bool isInt(string& s){
        int len = s.length();
        for(int i=0; i<len; i++){
            if(s[i]<'0' || s[i]>'9'){
                return false;
            }
        }
        return true;
    }
};
