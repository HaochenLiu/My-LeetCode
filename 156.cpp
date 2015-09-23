/*
156. Binary Tree Upside Down

Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
For example:
Given a binary tree {1,2,3,4,5},
   1
   / \
  2   3
 / \
4   5


return the root of the binary tree [4,5,2,#,#,3,1].
  4
  / \
 5   2
    / \
   3   1  


confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* temp = NULL;
        TreeNode* newRoot = NULL;
        temp = buildUpsideDownBT(root, newRoot);
        return newRoot;
    }
    
    TreeNode* buildUpsideDownBT(TreeNode* root, TreeNode*& newRoot) {
        if(root == NULL) return root;
        if(root->left == NULL && root->right == NULL) {
            newRoot = root;
            return root;
        }
        TreeNode* parent = buildUpsideDownBT(root->left, newRoot);
        parent->left = root->right;
        parent->right = root;
        root->left = NULL;
        root->right = NULL;
        return parent->right;
    }
};
