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
        stack<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);

        while(!q1.empty()) {
            TreeNode* tmp = q1.top();
            q1.pop();
            q2.push(tmp);
            
            if(tmp->right) {
                q1.push(tmp->right);
            }
    
            if(tmp->left) {
                q1.push(tmp->left);
            }
        }
        
        TreeNode* prev = q2.front();
        q2.pop();
        prev->left = NULL;
        while(!q2.empty()) {
            TreeNode* tmp = q2.front();
            q2.pop();
            prev->right = tmp;
            tmp->left = NULL;
            prev = tmp;
        }
        return;
    }
};
