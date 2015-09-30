/*
031. Next Permutation

http://fisherlei.blogspot.com/2012/12/leetcode-next-permutation.html
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

/*
Time: O(n)
Space: O(n)
Extra space: O(1)
n is the length of nums.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while(i > 0 && nums[i] <= nums[i - 1]) {
            i--;
        }
        reverse(nums.begin() + i, nums.end());
        if(i == 0) {
            return;
        }
        int j = i;
        while(j < nums.size() && nums[j] <= nums[i - 1]) {
            j++;
        }
        swap(nums[j], nums[i - 1]);        
    }
};
