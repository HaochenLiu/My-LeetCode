/*
386. Lexicographical Numbers

Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> rs;
        stack<int> stk;
        stk.push(1);
        while(!stk.empty())
        {
            int num = stk.top();
            rs.push_back(num);
            stk.pop();
            if(num + 1 <= n && num%10 < 9)
                stk.push(num + 1);
            if(10*num <= n)
                stk.push(10*num);
        }

        return rs;
    }
};
