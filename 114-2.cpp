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
 * Definition for binary tree
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *pre = NULL;
        while(!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            if(pre != NULL) {
                pre->right = cur;
                pre->left = NULL;
            }

            if(cur->right) {
                st.push(cur->right);
            }

            if(cur->left) {
                st.push(cur->left);
            }
            pre = cur;
        }
        pre->left = NULL;
        pre->right = NULL;
    }
};
