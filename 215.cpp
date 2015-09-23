/*
215. Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSortVariant(nums, nums.size() - k, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
    
    int swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void quickSortVariant(vector<int>& nums, int k, int start, int end) {
        int flag = start;
        swap(nums, start, flag);
        int flagNum = nums[start];
        int left = start;
        int right = end;
        while(left < right){
            while(left < right && nums[right] >= flagNum) {
                right--;
            }
            nums[left] = nums[right];
            while(left < right && nums[left] <= flagNum) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = flagNum;
        if(left > k) {
            quickSortVariant(nums, k, start, left - 1);
        } else if(left < k) {
            quickSortVariant(nums, k, left + 1, end);
        }
    }
};
