/*
129. Sum Root to Leaf Numbers

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
For example,
   1
   / \
  2   3


The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Return the sum = 12 + 13 = 25.
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
    int sumNumbersRecur(TreeNode* node, int cur) {
        if(node == NULL) return 0;
        if(node->left == NULL && node->right == NULL) return (cur * 10 + node->val);
        return sumNumbersRecur(node->left, cur * 10 + node->val) + sumNumbersRecur(node->right, cur * 10 + node->val);
    }

public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return root->val;
        return sumNumbersRecur(root->left, root->val) + sumNumbersRecur(root->right, root->val);
    }
};
