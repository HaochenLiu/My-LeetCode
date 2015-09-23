/*
114. Flatten Binary Tree to Linked List

Given a binary tree, flatten it to a linked list in-place.
For example,
Given
        1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:
  1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        flatten(root->left);
        flatten(root->right);
        if(root->left) {
            TreeNode* node = root->left;
            while(node->right) {
                node = node->right;
            }
            node->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }

        return;
    }
};
