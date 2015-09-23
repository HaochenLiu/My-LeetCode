/*
190. Reverse Bits

Reverse bits of a given 32 bits unsigned integer.
For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
Follow up:
If this function is called many times, how would you optimize it?
Related problem: Reverse Integer
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    uint32_t reverseBytes(uint32_t n) {
        n %= 256;
        int res = 0;
        int n1 = n / 128;
        int n2 = n % 128 / 64;
        int n3 = n % 64 / 32;
        int n4 = n % 32 / 16;
        int n5 = n % 16 / 8;
        int n6 = n % 8 / 4;
        int n7 = n % 4 / 2;
        int n8 = n % 2;
        
        return n1 + (n2 << 1) + (n3 << 2) + (n4 << 3) + (n5 << 4) + (n6 << 5) + (n7 << 6) + (n8 << 7);
    }
    
    uint32_t reverseBits(uint32_t n) {
        int n1 = n >> 24;
        int n2 = (n << 8) >> 24;
        int n3 = (n << 16) >> 24;
        int n4 = (n << 24) >> 24;
        int res = 0;
        
        n1 = reverseBytes(n1);
        n2 = reverseBytes(n2);
        n3 = reverseBytes(n3);
        n4 = reverseBytes(n4);

        res = n1 + (n2 << 8) + (n3 << 16) + (n4 << 24);
        return res;
    }
};
