/*
013. Roman to Integer
O(n)

Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.

//http://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97
//I（1）、V（5）、X（10）、L（50）、C（100）、D（500）、M（1000）
*/

/*
Time: O(1)
Space: O(1)
*/

class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int id = 0;
        int res = 0;

        while(s[id] == 'M') {
            res += 1000;
            id++;
        }

        if(s.substr(id, 2) == "CM") {
            res += 900;
            id += 2;
        }

        if(s.substr(id, 2) == "CD") {
            res += 400;
            id += 2;
        }

        if(s[id] == 'D') {
            res += 500;
            id++;
        }

        while(s[id] == 'C') {
            res += 100;
            id++;
        }

        if(s.substr(id, 2) == "XC") {
            res += 90;
            id += 2;
        }

        if(s.substr(id, 2) == "XL") {
            res += 40;
            id += 2;
        }

        if(s[id] == 'L') {
            res += 50;
            id++;
        }

        while(s[id] == 'X') {
            res += 10;
            id++;
        }

        if(s.substr(id, 2) == "IX") {
            res += 9;
            id += 2;
        }

        if(s.substr(id, 2) == "IV") {
            res += 4;
            id += 2;
        }

        if(s[id] == 'V') {
            res += 5;
            id++;
        }

        while(s[id] == 'I') {
            res += 1;
            id++;
        }

        return res;
    }
};
