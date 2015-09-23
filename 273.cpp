/*
273. Integer to English Words

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Hint:
Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)
*/

class Solution {
private:
    string unit_digit[10] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
    string Ten_to_Twenty_digit[11] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};
    string ten_digit[10] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred"};
    string res = "";
        
public:
    string helperUnderThousand(int num) {
        if(num == 0) return "";

        if(num >= 100) {
            if(res != "") res += " ";
            res += (unit_digit[num / 100 - 1] + " Hundred");
        }

        if(num % 100 == 0) return res;

        if(num % 100 >= 20) {
            if((num / 10) % 10 > 0) {
                if(res != "") res += " ";
                res += ten_digit[(num / 10) % 10 - 1];
            }
            
            if(num % 10 > 0) {
                if(res != "") res += " ";
                res += unit_digit[num % 10 - 1];
            }
        } else if(num % 100 >= 10) {
            if(res != "") res += " ";
            res += Ten_to_Twenty_digit[num % 100 - 10];
        } else {
            if(res != "") res += " ";
            res += unit_digit[num % 10 - 1];
        }
        return res;
    }
    
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        
        int billions = num / 1000000000;
        int millions = (num / 1000000) % 1000;
        int thousands = (num / 1000) % 1000;
        int ones = num % 1000;

        if(billions != 0) {
            helperUnderThousand(billions);
            res += " Billion";
        }
        
        if(millions != 0) {
            helperUnderThousand(millions);
            res += " Million";
        }

        if(thousands != 0) {
            helperUnderThousand(thousands);
            res += " Thousand";
        }

        if(ones != 0) {
            helperUnderThousand(ones);
        }
        
        return res;
    }
};
