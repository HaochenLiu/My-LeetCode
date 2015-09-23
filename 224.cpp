/*
224. Basic Calculator

Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
You may assume that the given expression is always valid.
Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23


Note: Do not use the eval built-in library function.
*/

class Solution {
public:
    int calculate(string s) {
        string postS = getPostString(s);    //获得后缀表达式
        cout << postS;
        stack<int> nums;
        int len = postS.length();
        int num1, num2;
        for (int i = 0; i<len; i++){
            switch (postS[i])
            {
            case '+':
                num1 = nums.top();
                nums.pop();
                num2 = nums.top();
                nums.pop();
                num1 = num1 + num2;
                nums.push(num1);
                break;
            case '-':
                num1 = nums.top();
                nums.pop();
                num2 = nums.top();
                nums.pop();
                num1 = num2 - num1;    //注意这里是num2减去num1
                nums.push(num1);
                break;
            case '#':
                break;
            default:
                int num = 0;
                while (i < len && postS[i] >= '0' && postS[i] <= '9'){
                    num = num * 10 + (postS[i] - '0');
                    i++;
                }
                i--;
                nums.push(num);
                break;
            }
        }
        return nums.top();
    }

private:
    string getPostString(string s){
        string postS = "";

        stack<char> op;
        int len = s.length();
        for (int i = 0; i<len; i++){
            switch (s[i]){
            case ' ':
                break;
            case '(':
                op.push('(');
                break;
            case ')':
                while (!op.empty() && op.top() != '('){
                    postS += op.top();
                    op.pop();
                }
                if (!op.empty() && op.top() == '('){
                    op.pop();
                }
                break;
            case '+':
            case '-':
                while (!op.empty() && op.top() != '('){
                    postS += op.top();
                    op.pop();
                }
                op.push(s[i]);
                break;
            default:
                while (i<len && s[i] >= '0'&&s[i] <= '9'){
                    postS += s[i];
                    i++;
                }
                postS += '#';   //分隔数字
                i--;
                break;
            }
        }
        while (!op.empty()){
            postS += op.top();
            op.pop();
        }

        return postS;
    }
};
