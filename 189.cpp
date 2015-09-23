/*
189. Rotate Array

Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Hint:
Could you do it in-place with O(1) extra space?
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

class Solution {
public:
    int gcd(int a,int b) {
        if(b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    void rotate(int nums[], int n, int k) {
        k = k % n;
        if(k == 0) {
            return;
        }

        for(int i = 0; i < gcd(n, k); i++) {
            int prev = i;
            int cur = i;
            int tmp = nums[i];
            while(1) {
                cur -= k;
                if(cur < 0) {
                    cur += n;
                }
                if(cur == i) {
                    nums[prev] = tmp;
                    break;
                }
                nums[prev] = nums[cur];
                prev = cur;
            }
        }
    }
};
