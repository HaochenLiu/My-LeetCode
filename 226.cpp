/*
226. Invert Binary Tree

Invert a binary tree.
    4
   /   \
  2     7
 / \   / \
1   3 6   9
to
    4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        if(root->left == NULL && root->right == NULL) return root;
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        root->left = invertTree(rightNode);
        root->right = invertTree(leftNode);
        return root;
    }
};
