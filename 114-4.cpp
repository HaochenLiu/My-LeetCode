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

/*
Time: O(n)
Space: O(1)
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
    void flatten(TreeNode *root) {
        while(root) {
            if(root->left) {
                TreeNode* pre = root->left;
                while(pre->right) {
                    pre = pre->right;
                }
                pre->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};
