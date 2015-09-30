/*
144. Binary Tree Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

  1
    \
     2
    /
   3

return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
Recursion
Time: O(n)
Space: O(n)
Extra space: O(h)
h is the height of the tree. 
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
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root) res.push_back(root->val);
        if(root && root->left) preorderTraversal(root->left);
        if(root && root->right) preorderTraversal(root->right);
        return res;
    }
};
