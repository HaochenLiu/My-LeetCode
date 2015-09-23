/*
067. Add Binary
http://shenxingfeng1988.blog.163.com/blog/static/10637600520112306124267/

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() == 0) return b;
        if(b.size() == 0) return a;
        if(a.size() < b.size()) {
            string tmp = a;
            a = b;
            b = tmp;
        }
        string res(a.size() + 1, '0');
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string na = a;
        string nb(a.size(), '0');
        for(int i = 0; i < b.size(); i++) {
            nb[i] = b[i];
        }
        
        for(int i = 0; i < a.size(); i++) {
            if(na[i] == '0' && nb[i] == '0') {
                if(carry == 1) {
                    res[i] = '1';
                    carry = 0;
                } else {
                    res[i] = '0';
                }
            } else if(na[i] != nb[i]) {
                if(carry == 1) {
                    res[i] = '0';
                    carry = 1;
                } else {
                    res[i] = '1';
                }
            } else {
                if(carry == 1) {
                    res[i] = '1';
                } else {
                    res[i] = '0';
                    carry = 1;
                }
            }
        }
        if(carry == 1) {
            res[a.size()] = '1';
        } else {
            res[a.size()] = '0';
        }
        reverse(res.begin(), res.end());
        if(res[0] == '0') {
            res.erase(res.begin());
        }
        return res;
    }
};
