/*
150. Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution {
public:
    int parseInt(string& x){
        stringstream ss;
        int res = 0;
        ss << x;
        ss >> res;
        return res;
    }
    void op(char op , stack<int>& st){
        int num1 , num2;
        num1 = st.top() ; st.pop();
        num2 = st.top() ; st.pop();
        switch(op){
           case '+' : st.push(num2 + num1);break;
           case '-' : st.push(num2 - num1);break;
           case '*' : st.push(num2 * num1);break;
           case '/' : st.push(num2 / num1);break;
        }
    }
    bool isOp(char op){
        return op == '+' || op == '-' || op == '*' || op == '/';
    }
    int evalRPN(vector<string> &tokens) {
        int res = 0;
        int num1 , num2;
        int size = tokens.size();
        stack<int> st;
        for(int i = 0 ; i < size ; i++){
            string token = tokens[i];
            if(isOp(token[0]) && token.length() == 1){
                op(token[0] , st);
            }else{
                st.push(parseInt(token));
            }
        }
        return st.top();
    }
};
