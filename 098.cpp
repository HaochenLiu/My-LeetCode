/*
098. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

/*
Time: O(n)
Space: O(logn)
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
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        if(!isValidBST(root->left)) return false;
        if(!isValidBST(root->right)) return false;
        if(root->left) {
            TreeNode* node = root->left;
            while(node->right) {
                node = node->right;
            }
            if(node->val >= root->val) {
                return false;
            }
        }

        if(root->right) {
            TreeNode* node = root->right;
            while(node->left) {
                node = node->left;
            }
            if(node->val <= root->val) {
                return false;
            }
        }

        return true;
    }
};
