/*
227. Basic Calculator II

Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
You may assume that the given expression is always valid.
Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5


Note: Do not use the eval built-in library function.
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
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
                num1 = num2 - num1; //注意这里是num2减去num1
                nums.push(num1);
                break;
            case '*':
                num1 = nums.top();
                nums.pop();
                num2 = nums.top();
                nums.pop();
                num1 = num2 * num1;
                nums.push(num1);
                break;
            case '/':
                num1 = nums.top();
                nums.pop();
                num2 = nums.top();
                nums.pop();
                num1 = num2 / num1;
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
            case '*':
            case '/':
                while (!op.empty() && op.top() != '(' && op.top() != '+' && op.top() != '-'){    //这里体现出了*, /的优先级比+, -高
                    postS += op.top();
                    op.pop();
                }
                op.push(s[i]);
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
