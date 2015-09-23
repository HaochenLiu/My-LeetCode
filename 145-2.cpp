/*
145. Binary Tree Postorder Traversal

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

  1
    \
     2
    /
   3

return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> current;
        stack<TreeNode*> next;
        current.push(root);
        while(!current.empty()) {
            TreeNode* node = current.top();
            current.pop();
            next.push(node);
            if(node->left) {
                current.push(node->left);
            }
            
            if(node->right) {
                current.push(node->right);
            }
        }

        while(!next.empty()) {
            res.push_back(next.top()->val);
            next.pop();
        }

        return res;
    }
};
