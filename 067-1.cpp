/*
067. Add Binary

http://shenxingfeng1988.blog.163.com/blog/static/10637600520112306124267/
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

/*
Time: O(n+m)
Space: O(n+m)
Extra space: O(1)
*/

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() == 0) return b;
        if(b.size() == 0) return a;
        
        string result;
        int length = max(a.size(), b.size());
        //add '0' before the front of the short string
        int dif = a.size() - b.size();
        
        string c(abs(dif), '0');

        string na;
        string nb;
        if(dif >= 0) {
            nb = c + b;
            result = AddBinaryEqual(a, nb, length);
        } else {
            na = c + a;
            result = AddBinaryEqual(na, b, length);
        }
        
        return result;
    }
    
private: 
    string AddBinaryEqual(string x, string y, int size) {
        int count = 0;
        int sum = 0;
        string result = "";
        for(int i = size - 1; i >= 0; --i) {
            sum = (x[i] - '0') + (y[i] - '0') + count; // 0, 1, 2, 3
            char c = sum % 2 + '0';
            result = c + result ;
            count = sum / 2;
        }
        
        if(count == 1) {
            result = '1' + result;
        }
        
        return result;
    }
};
