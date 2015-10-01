/*
108. Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/*
Time: O(n)
Space: O(n)
Extra space: O(logn)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* sortedArrayToBSTRecur(vector<int>& nums, int start, int end) {
        if(start > end) return NULL;
        int mid = start + (end - start + 1) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTRecur(nums, start, mid - 1);
        root->right = sortedArrayToBSTRecur(nums, mid + 1, end);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return sortedArrayToBSTRecur(nums, 0, nums.size() - 1);
    }
};
