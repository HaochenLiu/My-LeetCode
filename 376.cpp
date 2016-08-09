/*
376. Wiggle Subsequence

A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?

Credits:
Special thanks to @agave and @StefanPochmann for adding this problem and creating all test cases.
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        
        if (size == 0) {
            return 0;
        }
        
        /** up[i] is the length of a longest wiggle subsequence of {nums[0],...,nums[i}}, with a
            positive difference between its last two numbers. This subsequence may or may not
            include nums[i] and there may be several such subsequences (of the same length).
            We call this a subsequence of type U.
         */
        vector<int> up(size, 0);
        /** down[i] is the length of a longest wiggle subsequence of {nums[0],...,nums[i}}, with a
            negative difference between its last two numbers. This subsequence may or may not
            include nums[i] and there may be several such subsequences (of the same length).
            We call this a subsequence of type D.
         */
        vector<int> down(size, 0);
        
        // At i=0, there is only one number and we can use it as a subsequence, i.e up[0]=down[0]=1
        up[0] = 1;
        down[0] = 1;
        for(int i=1; i<size; ++i){
            
            if (nums[i] > nums[i-1]) {
                /** If nums[i] > nums[i-1], then we can use nums[i] to make a longer subsequence of type U
                    We first use a subsequence of type D in {0,...,i-1} (its length is down[i-1]).
                    Let N be the last number of this subsequence.
                    If nums[i] > N, then we can add nums[i] to the subsequence and it gives us a longer
                    valid subsequence of type U.
                    If nums[i] <= N, then we can replace N with nums[i-1] (we still have a valid
                    subsequence of type D since N >= nums[i] > nums[i-1] i.e. N > nums[i-1]),
                    and then add nums[i] to the subsequence, and we have a longer subsequence of type U.
                    Therefore up[i] = down[i-1] + 1
                    
                    There is no gain in using nums[i] to make a longer subsequence of type D.
                    Proof: Let N be the last number of a subsequence of type U
                    in {0,...,i-1}.
                    Assume we can use nums[i] to make a longer subsequence of type D. Then:
                    (1) N cannot be nums[i-1], otherwise we would not be able to use nums[i]
                    to make a longer subsequence of type D as nums[i] > nums[i-1]
                    (2) Necessarily nums[i] < N, and therefore nums[i-1] < N since nums[i-1] < nums[i].
                    But this means that we could have used nums[i-1] already to make a longer
                    subsequence of type D.
                    So even if we can use nums[i], there is no gain in using it, so we keep the old value of
                    down (down[i] = down[i-1])
                */
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            }
            else if (nums[i] < nums[i-1]) {
                /** The reasoning is similar if nums[i] < nums[i-1] */
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            }
            else {
                /** if nums[i] == nums[i-1], we cannot do anything more than what we did with
                     nums[i-1] so we just keep the old values of up and down
                */
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        return max(up[size-1], down[size-1]);
    }
};
